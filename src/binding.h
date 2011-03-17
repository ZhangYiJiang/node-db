// Copyright 2011 Mariano Iglesias <mgiglesias@gmail.com>
#ifndef SRC_NODE_DB_BINDING_H_
#define SRC_NODE_DB_BINDING_H_

#include <node.h>
#include <node_events.h>
#include <string>
#include "./node_defs.h"
#include "./connection.h"
#include "./exception.h"
#include "./query.h"

namespace node_db {
class Binding : public node::EventEmitter {
    public:
        Connection* connection;

    protected:
        struct connect_request_t {
            Binding* binding;
            const char* error;
        };
        static v8::Persistent<v8::String> syReady;
        static v8::Persistent<v8::String> syError;

        Binding();
        ~Binding();
        static void Init(v8::Handle<v8::Object> target, v8::Persistent<v8::FunctionTemplate> constructorTemplate);
        static v8::Handle<v8::Value> Connect(const v8::Arguments& args);
        static v8::Handle<v8::Value> Disconnect(const v8::Arguments& args);
        static v8::Handle<v8::Value> IsConnected(const v8::Arguments& args);
        static v8::Handle<v8::Value> Escape(const v8::Arguments& args);
        static v8::Handle<v8::Value> Table(const v8::Arguments& args);
        static v8::Handle<v8::Value> Field(const v8::Arguments& args);
        static v8::Handle<v8::Value> Query(const v8::Arguments& args);
        static int eioConnect(eio_req* req);
        static void connect(connect_request_t* request);
        static void connectFinished(connect_request_t* request);
        static int eioConnectFinished(eio_req* eioRequest);
        virtual v8::Handle<v8::Value> set(const v8::Arguments& args);
        virtual v8::Persistent<v8::Object> createQuery() const = 0;
};
}

#endif  // SRC_NODE_DB_BINDING_H_
