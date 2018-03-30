#ifndef SERVER_H
#define SERVER_H

#include "message.h"
#include "queue.h"

class Server {
    Queue<Message> requests;
    Queue<Message> replies;
    Queue<Message> errors;
    Queue<Message> info;

    public:
        void enqueue(Message message);
        void processQueues();
        void printQueues();
};

#endif
