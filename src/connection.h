// Copyright 2011 Mariano Iglesias <mgiglesias@gmail.com>
#ifndef SRC_NODE_DB_CONNECTION_H_
#define SRC_NODE_DB_CONNECTION_H_

#include <stdint.h>
#include <string>
#include "./exception.h"
#include "./result.h"

namespace node_db {
class Connection {
    public:
        char quoteString;
        char quoteField;
        char quoteTable;

        Connection();
        virtual ~Connection();
        virtual std::string getHostname() const;
        virtual void setHostname(const std::string& hostname);
        virtual std::string getUser() const;
        virtual void setUser(const std::string& user);
        virtual std::string getPassword() const;
        virtual void setPassword(const std::string& password);
        virtual std::string getDatabase() const;
        virtual void setDatabase(const std::string& database);
        virtual uint32_t getPort() const;
        virtual void setPort(uint32_t port);
        virtual bool isOpened() const;
        virtual void open() throw(Exception&) = 0;
        virtual void close() = 0;
        virtual std::string escape(const std::string& string) const throw(Exception&) = 0;
        virtual std::string version() const = 0;
        virtual Result* query(const std::string& query) const throw(Exception&)  = 0;

    protected:
        std::string hostname;
        std::string user;
        std::string password;
        std::string database;
        uint32_t port;
        bool opened;
};
}

#endif  // SRC_NODE_DB_CONNECTION_H_
