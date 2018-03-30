#include "messagefactory.h"
#include "message.h"
#include "server.h"

int main() {
    MessageFactory msgFactory;
    Server server;

    for (int day = 1; day <= 31; day++) {
        for (int i = 0; i < 33; i++) {
            // Generate 33 messages a day
            Message msg = msgFactory.generate(day);
            server.enqueue(msg);    
        }
        
        // Process queues once a day
        server.processQueues();
    }
    server.printQueues();
    return 0;
}
