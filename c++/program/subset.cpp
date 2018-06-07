#include <iostream>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

class CStr {
  private:
  char *str;
  int length;
  int capcity;

  public:
  CStr(const char *c_str);
  ~CStr();
  void DisplayAllSubStrRecrusive();
  void DisplayAllSubStrNotRecrusive();
  int  GetLength();
  char *GetCStr();

  CStr&
  operator += (const char* c_str) {
    int len;
    char *ptr = NULL;
    len = strlen(c_str);
    if (this->length + len >= this->capcity) {
      ptr = new char[this->capcity * 2]; 
      assert(ptr != NULL);
      memset(ptr, '\0', this->capcity);
      memcpy(ptr, this->str, this->length);
      memcpy(ptr + this->length, c_str, len);
      this->length += len ;
      this->capcity *= 2;
      delete str;
      this->str = ptr;
    } else {
      memcpy(this->str + this->length, c_str, len);
      this->length += len;
    }
    return *this;
  }


  const CStr&
  operator + (const char* c_str) {
    int len;
    char *ptr = NULL;
    len = strlen(c_str);
    if (this->length + len >= this->capcity) {
      ptr = new char[this->capcity * 2]; 
      assert(ptr != NULL);
      memset(ptr, '\0', this->capcity);
      memcpy(ptr, this->str, this->length);
      memcpy(ptr + this->length, c_str, len);
      this->length += len ;
      this->capcity *= 2;
      delete str;
      this->str = ptr;
    } else {
      memcpy(this->str + this->length, c_str, len);
      this->length += len;
    }
    return *this;
  }


  CStr&
  operator = (CStr istr) {
    int len;
    char *ptr = NULL;
    char *c_str = NULL;
    len = istr.GetLength();
    if (this->length + len >= this->capcity) {
      ptr = new char[this->capcity * 2];
      c_str = istr.GetCStr();
      assert(ptr != NULL);
      assert(c_str != NULL);
      memset(ptr, '\0', this->capcity);
      memcpy(ptr, this->str, this->length);
      memcpy(ptr + this->length, c_str, len);
      this->length += len ;
      this->capcity *= 2;
      delete str;
      this->str = ptr;
    } else {
      memcpy(this->str + this->length, c_str, len);
      this->length += len;
    }
    return *this;
  }

  protected:

  private:
  void _initialStr(const char *c_str);
  void _subStrRecrusive(int low, int high);
  int _getLength();

};

CStr::CStr(const char *c_str) {
  _initialStr(c_str);
}

CStr::~CStr() {


}

void CStr::DisplayAllSubStrRecrusive() {
  _subStrRecrusive(0, this->length - 1); 
}

void CStr::_subStrRecrusive(int low, int high) {
  int right = high, left = low, index;
    if (low > high) {
      return;
    }

    while (left <= right) {
      index = low;
      while (index <= right) {
        cout << this->str[index];
        index++;
      }
      right--;
      cout << endl;
    }
  _subStrRecrusive(low + 1, high);
}

int CStr::GetLength() { 
  return this->GetLength();
}

int CStr::_getLength() {
  return this->length;
}

char* CStr::GetCStr() { 
  return this->str;
}

void CStr::DisplayAllSubStrNotRecrusive() {
  int start;

  for (int index = 0; index < this->length; index++) {
    for (int sub_index = 0; sub_index < this->length; sub_index++) {
      start = index; 
      while (start <= sub_index) {
        cout << this->str[start];
        start++;
      }
      cout << endl;
    }
  }
}

void CStr::_initialStr(const char *c_str) {
  int len = strlen(c_str);

  this->str = NULL;
  this->str = new char[len * 2];
  assert(this->str != NULL);
  memset(this->str, '0', len * 2);
  memcpy(this->str, c_str, len * 2);
  this->length = len;
  this->capcity = len * 2;
}


int main(void) {
  CStr str("abc");
  str += "cdefgh";

  str = str + "mm";

  cout << "recrusive" << endl;
  str.DisplayAllSubStrRecrusive();
  cout << "not recrusive" << endl;
  str.DisplayAllSubStrNotRecrusive();

  return 0;
}
