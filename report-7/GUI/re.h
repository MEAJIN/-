#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

typedef struct Movie {
	std::string stdio; // 영화사 이름
	std::string name; // 현재 상영중인 영화
}Movie;
typedef struct MovieReservation {
	Movie m;
	int seatState[20][20]{};
}MovieReservation;

class reservation {
private:
	
public:
	std::vector<MovieReservation> MR;
	reservation() {
		std::fstream ml("movie.txt");
		std::string temp;
		while (ml >> temp) {
			int i =0;
			MovieReservation movie;
			movie.m.stdio = temp;
			ml >> temp;
			movie.m.name=temp;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					ml >> temp;
					movie.seatState[i][j] = atoi(temp.c_str());
				}
			}
			MR.push_back(movie);
		}
		
	}
	//void showseat(int n);
	//void Update(fstream ofs);
};