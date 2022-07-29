#ifndef _IP_H
#define _IP_H

#include <cmath>
#include <iostream>
#include <vector>

class IP {
private:
  std::string ip;
  //std::string IPport;
  int ipIndex;
  unsigned int IPValue;
  int degree;
  int degreeIn;

public:
  IP();
  IP(std::string ip, int ipIndex);

  std::string getIp();
  unsigned int getIPValue();
  int getIpIndex();
  void addDegreeOut();
  void addDegreeIn();
  int getDegreeOut();
  int getDegreeIn();
  std::string getData();

  // sobrecarga
  bool operator==(const IP &);
  bool operator!=(const IP &);
  bool operator>(const IP &);
  bool operator>=(const IP &);
  bool operator<(const IP &);
  bool operator<=(const IP &);
};
#endif // _IP_H