#include <iostream>
#include <string>
using namespace std;


class DBAccess {
public:
  DBAccess() {

  }

  ~DBAccess() {
    cout << "Deconstruct dbaccess" << endl;
  }
  virtual void accessTable(string sql) = 0;
};


class SqlServer: public DBAccess {
public:
  SqlServer() {
  }
  virtual void accessTable(string sql) {
    cout << "sql server:" << sql << endl;
  } 
};


class MySql: public DBAccess {
public:
  MySql() {

  }
  virtual void accessTable(string sql) {
    cout << "sql server:" << sql << endl;
  } 
};

class DBManage {
public:
  DBAccess *dbaccess;

public:
  DBManage(DBAccess *access) {
    dbaccess = access;
  }
  ~DBManage() {
    cout << "deconstructor" << endl;
  }
  virtual void accessObject() {
    cout << "DBManage access object" << endl;
  }
  virtual void log() {
    cout << "DBManage log" << endl;
  }
};

class XMLLog: public DBManage {
public:
  XMLLog(DBAccess *access):DBManage(access) {

  }
  virtual void log() {
    cout << "xml log" << endl;
  }
};


class HTTPLog: public DBManage {
public:
  HTTPLog(DBAccess *access):DBManage(access) {

  }
  virtual void log() {
    cout << "http log" << endl;
  }
};

int main(void) {
  DBAccess *dba = new SqlServer();
  DBManage *dbm = new HTTPLog(dba);
  dba->accessTable("hei hei hei");
  dbm->log();
  return 0;
}
