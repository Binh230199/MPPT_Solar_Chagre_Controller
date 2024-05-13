/*
 * Singleton.h
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

template<typename T>
class Singleton
{
    public:
        static T& getInstance()
        {
            if (mInstance == nullptr)
            {
                mInstance = new T();
            }

            return *mInstance;
        }
        static void destroy()
        {
            if (mInstance != nullptr)
            {
                delete mInstance;
                mInstance = nullptr;
            }
        }

    protected:
        Singleton()
        {
        }
        virtual ~Singleton()
        {
        }
        Singleton(const Singleton&) = delete;
        void operator=(const Singleton&) = delete;

    private:
        static T *mInstance;
};

template<typename T>
T *Singleton<T>::mInstance { nullptr };

#endif /* SINGLETON_H_ */
