/*
 * File Looper.h in project RRUtils
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef LOOPER_H_
#define LOOPER_H_

#include <thread>

namespace RRUtils {

    class Looper {
        private:
            bool continueLoop;
            std::function<void(Looper*)> callback;
            /**
             * interval in which the loop will run in milliseconds.
             * It's default value is 250 milliseconds.
             */
            long int interval;

        public:
            Looper();

            explicit Looper(std::function<void(Looper*)> callback, long int interval = 250);

            virtual ~Looper();

            void setCallback(std::function<void(Looper*)> callback);

            void setInterval(long int interval);

            void start();

            /**
             * Starts the loop and on each loop it calls the function callback.
             *
             * @param callback function, it is called at each loop of the looper.
             */
            void start(std::function<void(Looper*)> callback);

            bool isRunning();

            void stop();
    };

} /* namespace RRUtils */

#endif /* LOOPER_H_ */
