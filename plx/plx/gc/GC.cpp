#include <cassert>
#include <iostream>
#include <vector>

#include <plx/data/Triple.hpp>
#include <plx/expr/Identifier.hpp>
#include <plx/gc/GC.hpp>
#include <plx/literal/Symbol.hpp>
#include <plx/vm/VM.hpp>

namespace PLX {

    GC::GC() {}

    GC::~GC() {
        _deleteAllObjects();
    }

    void GC::addRoot(Object* obj) {
        _rootObjects.push_back(obj);
        _nRoots++;
    }

    void GC::setRegistrationType(RegistrationType registrationType) {
        _registrationType = registrationType;
    }

    void GC::registerObject(Object* obj) {
        registerObject(obj, _registrationType);
    }

    void GC::registerObject(Object* obj, RegistrationType registrationType) {
        switch (registrationType) {
            case RegistrationType::REGULAR:
                {
                    _spine.push_back(obj);
                    size_t size = sizeof(*obj);
                    _nRegistered++;
                    _sizeRegistered += size;
                    _nNew++;
                    _sizeNew += size;
                    if (_nNew >= _nThreshold || _sizeNew >= _sizeThreshold) {
                        _isGcNeeded = true;
                    }
                }
                break;
            case RegistrationType::PERMANENT:
                // permanent objects are never marked or swept
                _permanentObjects.push_back(obj);
                _nPermanent++;
                break;
            // case RegistrationType::UNREGISTERED:
            //     break;
            default:
                assert(false);
                break;
        }
    }

    void GC::collect() {
        _nLastReclaimed = 0;
        _sizeLastReclaimed = 0;
        mark();
        sweep();
        _nNew = 0;
        _sizeNew = 0;
        _isGcNeeded = false;
    }

    bool GC::isGcNeeded() {
        return _isGcNeeded;
    }

    void GC::mark() {
        std::vector<Object*> objs;
        for (Object* currObj : _rootObjects) {
            currObj->mark(objs);
        }
    }

    void GC::mark(std::vector<Object*>& objs) {
        // Bugged based on Do and If tests
        while (!objs.empty()) {
            Object* toMark = objs.back();
            toMark->mark(objs);
            objs.pop_back();
        }
    }

    void GC::sweep() {
        // currently throws segmentation fault
        // instructions need to be updated
        for (Object* currObj : _spine) {
            if (currObj->isMarked()) {
                currObj->setMark(false);
            // currently operating under assumption that the second
            // bullet point was meant to say unmarked
            } else if (!currObj->isMarked()) {
                _spine.remove(currObj);
                _dispose(currObj);
            }
        }
    }

    int GC::nPermanent() {
        return _nPermanent;
    }

    int GC::nRoots() {
        return _nRoots;
    }

    int GC::nRegistered() {
        return _nRegistered;
    }

    void GC::showPermanent() {
        int n = 0;
        for (Object* obj : _permanentObjects) {
            std::clog << n++ << ". " << obj << " :: " << obj->typeName() << "\n";
        }
    }

    void GC::showRoots() {
        int n = 0;
        for (Object* obj : _rootObjects) {
            std::clog << n++ << ". " << obj << " :: " << obj->typeName() << "\n";
        }
    }

    void GC::showSpine() {
        int n = 0;
        for (Object* obj : _spine) {
            std::clog << n++ << ". " << obj << " :: " << obj->typeName() << "\n";
        }
    }

    void GC::_deleteAllObjects() {
        _deleteList(_spine);
        _nRegistered = 0;
        _deleteList(_permanentObjects);
        _nPermanent = 0;
        _nRoots = 0;
    }

    void GC::_deleteList(std::list<Object*>& list) {
        while (!list.empty()) {
            Object* obj = list.front();
            list.pop_front();
            _dispose(obj);
        }
        assert(list.size() == 0);
    }

    void GC::_dispose(Object* obj) {
        _nLastReclaimed++;
        size_t size = sizeof(*obj);
        _sizeLastReclaimed += size;
        delete obj;
        _nRegistered--;
        _sizeRegistered -= size;
    }

}
