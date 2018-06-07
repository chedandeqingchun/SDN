#include <iostream>
#include <string.h>

template <class T>
class WrapChar {
public:
  WrapChar(T* ptr = NULL):_ptr(ptr) {

  }

  ~WrapChar() {
    std::cout << "resoure was released" << std::endl;
    delete _ptr;
  }

public:
  T *_ptr;
};


class CMyString {
public:
  CMyString(const char* pData = NULL) { 
    int istrLen = 0; 

    if (pData != NULL) {
      istrLen = strlen(pData);
      m_pData._ptr = new char[istrLen + 1];
      memset(m_pData._ptr, '\0', istrLen + 1);
      strncpy(m_pData._ptr, pData, istrLen + 1);
    }

  }

  CMyString(const CMyString& str) {
    m_pData._ptr = new char[strlen(str.m_pData._ptr) + 1];
    memset(m_pData._ptr, '\0', strlen(str.m_pData._ptr) + 1);
    strncpy(m_pData._ptr, str.m_pData._ptr, strlen(str.m_pData._ptr) + 1);
  }

  ~CMyString(void) {

  }

  CMyString& operator=(const CMyString &str) {

    if (this != &str) {
      CMyString strTemp(str);
      
      char *tempPtr = strTemp.m_pData._ptr;
      strTemp.m_pData._ptr = this->m_pData._ptr;
      this->m_pData._ptr = tempPtr;
    }

    return *this;
  }

private:
  WrapChar<char> m_pData;

};


int main(void) {
  const char *pstr1 = "liudj";
  const char *pstr2 = "director";

  CMyString str1(pstr1);

  CMyString str2(pstr2);

  str1 = str2;


  return 0;
}
