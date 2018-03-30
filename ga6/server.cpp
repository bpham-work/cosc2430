#include <iostream>
#include "server.h"
#include "message.h"
#include "queue.h"
#include "sqstype.h"
using namespace std;

void Server::enqueue(Message message) {
    if (message.sqsType == REQUEST) {
        requests.enqueue(message);
    } else if (message.sqsType == REPLY) {
        replies.enqueue(message);
    } else if (message.sqsType == ERROR) {
        errors.enqueue(message);
    } else if (message.sqsType == INFO) {
        info.enqueue(message);
    }
}

void Server::processQueues() {
    Queue<Message> remainingRequests;
    Queue<Message> remainingErrors;

    // Delete requests older than 4 days
    while (!requests.isEmpty()) {
        Message msg = requests.peek();
        msg.incrementDaysPassed();
        if (msg.daysPassed < 4) {
            remainingRequests.enqueue(msg);
        }
        requests.dequeue();
    }

    // Delete all replies
    while (!replies.isEmpty()) {
        replies.dequeue();
    }
    
    // Process up to 5 errors per day
    // Delete errors older than 10 days
    int errorProcessCount = 0;
    while (!errors.isEmpty() && errorProcessCount < 5) {
        errorProcessCount++;
        Message message = errors.peek();
        message.incrementDaysPassed();
        if (message.daysPassed < 10) {
            remainingErrors.enqueue(message);
        }
        errors.dequeue();
    }

    requests = remainingRequests;
    errors = remainingErrors;
}

void Server::printQueues() {
    Queue<Message> tempRequests;
    Queue<Message> tempReplies;
    Queue<Message> tempErrors;
    Queue<Message> tempInfo;
    
    int requestCount = 1; 
    int replyCount = 1;
    int errorCount = 1;
    int infoCount = 1;
    cout << "----- REQUEST QUEUE CONTENTS -----" << endl;
    while (!requests.isEmpty()) {
        Message message = requests.dequeue();
        cout << "Request " << requestCount++ << ": " << message.toString();
        cout << endl;
        tempRequests.enqueue(message);
    }
    cout << "----- REPLY QUEUE CONTENTS -----" << endl;
    while (!replies.isEmpty()) {
        Message message = replies.dequeue();
        cout << "Reply " << replyCount++ << ": " << message.toString();
        cout << endl;
        tempReplies.enqueue(message);
    }
    cout << "----- ERROR QUEUE CONTENTS -----" << endl;
    while (!errors.isEmpty()) {
        Message message = errors.dequeue();
        cout << "Error " << errorCount++ << ": " << message.toString();
        cout << endl;
        tempErrors.enqueue(message);
    }
    cout << "----- INFO QUEUE CONTENTS -----" << endl;
    while (!info.isEmpty()) {
        Message message = info.dequeue();
        cout << "Info " << infoCount++ << ": " << message.toString();
        cout << endl;
        tempInfo.enqueue(message);
    }
    requests = tempRequests;
    replies = tempReplies;
    errors = tempErrors;
    info = tempInfo;
}
