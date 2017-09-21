/*
 * File Looper.cpp in project RRUtils
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Looper.h"

using namespace std;

namespace RRUtils {

    Looper::Looper() : Looper::Looper(nullptr, 250) {}

    Looper::Looper(std::function<void(Looper*)> callback, long int interval) :
            continueLoop(false), callback(callback), interval(interval) {
    }

    Looper::~Looper() {

    }

    void Looper::setCallback(std::function<void(Looper*)> callback) {
        this->callback = callback;
    }

    void Looper::setInterval(long int interval) {
        this->interval = interval;
    }


    void Looper::start() {
        if (this->continueLoop) { // If it has already begun, then ignore call
            return;
        }

        this->continueLoop = true;

        chrono::milliseconds intervalMilliseconds(this->interval);

        while (this->continueLoop) {
            this->callback(this);
            this_thread::sleep_for(intervalMilliseconds);
        }
    }

    void Looper::start(std::function<void(Looper*)> callback) {
        this->setCallback(callback);
        this->start();
    }

    bool Looper::isRunning() {
        return this->continueLoop;
    }

    void Looper::stop() {
        this->continueLoop = false;
    }
} /* namespace RRUtils */
