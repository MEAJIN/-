/*		 영화 예매 프로그램			 */

#include "R.h"

typedef struct Movie{
	string stdio; // 영화사 이름
	string now_showing; // 현재 상영중인 영화
	string coming_soon; // 개봉 예정중인 영화
}Movie;
int check(Reservation* R, int m , int L, int C); // 좌석 범위 체크
int check(Reservation* R, int m , char L, int C); // 좌석 범위 체크
void InputMovie(Movie *M, int n);
void inline PrintMovie(Movie *M, int n , Reservation* R);
void MENU(int &x, int &y);

int main()
{
	int max = MAX; // 이미 할당된 배열의 최대 크기를 세는 변수
	int num =0;
	int N;

	/////////////////////////////////////////////////////////////////////////
	cout << "              영화정보를 입력하세요"; 
	cout << endl;

	Movie *M = new Movie[max]; // 영화사 4개까지 입력
	while(1)
	{
		if(num == max)
		{
			max +=1;
			Movie *temp = new Movie[max]; // 할당된 크기만큼 새로운 구조체포인터 temp 동적할당
			memcpy (temp,M,(num)*sizeof(Movie)); // 문자열 복사기능
			//delete M; // 동적으로 할당한 M 할당 해제
			M = temp;
		}

		for(int i = num; i<max ; i++)
		{
			InputMovie(M,i);
			num++;
		}
		
		cout << "영화정보를 더 입력하시겠습니까? (1.Yes, 2.No)";
		cin >> N;
		cout << "\n";
		
		if(N==2) // NO 입력시 무한루프 종료
			break;

	} // while 종료

	cout << "영화정보를 모두 입력하셨습니다. "<< endl;
	cout << "영화 예매 프로그램을 시작하겠습니다." << endl;
	Sleep(700);

	system("cls");
	///////////////////////////////////////////////////////////////////////
	int X=15,Y=4+num ,x,y;
	int menu;
	int m;

	Reservation* R = new Reservation[max]; // 영화 갯수만큼 R 동적할당
	VIP_Reservation *VIP_R = new VIP_Reservation[max]; // 영화 갯수마다 VIP_R 동적할당

	while(1) // 무한루프
	{
		PrintMovie(M,num,R); // 영화 정보 출력
		x=X,y=Y; // 좌표값 변수
		MENU(x,y); // 메뉴 출력
		cin >> menu; 
	
		if(menu == 1) // 일반 영화 예매
		{
			char L; // 행
			int C; // 열
			y+=2;
			gotoxy(x,y);
			cout << "영화관의 번호를 입력해주세요 : ";
			cin >> m;
			m--;
			y+=2; x+=6;
			R[m].place_situation(x,y); // m관의 영화 자리 표시
			cout << "좌석을 입력해주세요(ex> A 1) : ";
			cin >> L >> C;

			if(check(R,m,L,C) == 99) // 입력된 좌석이 범위에 맞지않으면
			{
				while(check(R,m,L,C) == 99) // 맞지 않으면 계속 반복
				{
					gotoxy(x,y+7);
					cout << "                                   "; // 표시된 좌석을 지워주는 역활
					gotoxy(x,y+7);
					cout << "좌석을 다시 입력해주세요 : "; // 좌석 다시 입력받기
					cin >> L >> C;
					check(R,m,L,C); // 범위에 맞는지 계속 체크
				}
			}
			// 범위에 맞으면
			R[m].ticket(L,C); // 해당 좌석 티켓팅
			R[m].place_situation(x,y); // 바뀐 좌석 출력
			gotoxy(x,y+9);
			cout << "예매가 완료되었습니다." ;
			gotoxy(x-1,y+10);
			
			if(M[m].coming_soon != "X") // 개봉영화가 있다면
			{	// 해당 stdio 의 개봉영화 홍보 
				cout << M[m].stdio <<"의 '"<<M[m].coming_soon <<"'이 개봉예정입니다.";
				gotoxy(x,y+11);
				cout <<"많은 관심 부탁드립니다.";}
			VIP_R[m].ticket(L,C); // VIP 클래스 같은자리에 티켓팅 (두개의 클래스의 좌석이 티켓팅)
		}
		else if(menu == 2) // VIP 영화 예매
		{
			char L;
			int C;
			y+=2;
			gotoxy(x,y);
			cout << "영화관의 번호를 입력해주세요 : ";
			cin >> m;
			m--;
			y+=2; x+=6;
			VIP_R[m].place_situation(x,y); // VIP 좌석 표시 (+기능) 좋은자리 표시
			cout << "좌석을 입력해주세요(ex> A 1) : ";
			cin >> L >> C;
			
			if(check(R,m,L,C) == 99) // 입력된 좌석이 범위에 맞지않으면
			{
				do
				{
					gotoxy(x,y+7);
					cout << "                                   "; 
					gotoxy(x,y+7);
					cout << "좌석을 다시 입력해주세요 : ";
					cin >> L >> C;
					check(R,m,L,C);
				}while(check(R,m,L,C) == 99);
			}
			// 좌석이 범위에 맞으면
			VIP_R[m].ticket(L,C); // 해당 자리 티켓팅
			VIP_R[m].place_situation(x,y); // 바뀐 좌석 출력
			gotoxy(x-4,y+9);
			VIP_R[m].discount(); // 할인쿠폰 적용 (VIP클래스 전용)
			y++;
			gotoxy(x,y+10);
			cout << "예매가 완료되었습니다." ;
			gotoxy(x-1,y+11);
			if(M[m].coming_soon != "X") // 개봉영화가 있다면
			{	//해당 studio의 개봉영화 홍보
				cout << M[m].stdio <<"의 '"<<M[m].coming_soon <<"'이 개봉예정입니다.";
				gotoxy(x,y+12);
				cout <<"많은 관심 부탁드립니다.";}
			R[m].ticket(L,C); // 일반자리도 티켓표시
	
		}
		else // 종료 
		{
			gotoxy(X+4,Y+4);
			cout << "프로그램이 종료됩니다.";
			break;
		}
		Sleep(3000); // 3초 정지 후
		system("cls"); // 화면 초기화

	}

	Sleep(1000); // 무한루프를 벗어나면 1초 멈춤
	delete[] R; // 메모리 해제
	delete[] VIP_R; // 메모리 해제

	//소멸자 호출
}
void MENU(int &x, int &y) // 좌표가 다같이 바뀌어야하므로 레퍼런스로 매개변수
{
	gotoxy(x,y);
	cout << "1.      영화 예매하기" ;
	y++;
	gotoxy(x,y);
	cout << "2. VIP회원으로 영화 예매하기" ;
	y++;
	gotoxy(x,y);
	cout << "3.         종료"<< endl;
	gotoxy(x+30,y);
	cout << "\n" <<  "\n" << "             "  << "☞ ";

}
void gotoxy(int x, int y) // 커서의 위치를 이동시키는 함수
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
void InputMovie(Movie *M, int n)
{
	cin.clear(); // 버퍼 비워주기
	fflush(stdin); // 버퍼 비워주기

	cout << "▶ stdio : ";
	getline(cin,M[n].stdio);
	cout << "▶ now_showing : ";
	getline(cin,M[n].now_showing);
	cout << "▶ coming_soon : ";
	getline(cin,M[n].coming_soon);
	cout <<"\n";

}
void inline PrintMovie(Movie *M, int n, Reservation* R)
{
	for(int i=0;i<n;i++) // 첫번째 고객부터 입력한 고객번호까지 출력
	{
		gotoxy(15,3+i);
		cout << (i+1) <<"관     " ;
		cout.setf(ios_base::left); // 왼쪽정렬
		cout.width(10); // 너비 10
		cout << M[i].stdio ;
		cout.width(12);
		cout << M[i].now_showing ;
		gotoxy(47,3+i);
		cout << R[i].remain();
	}

}
int check(Reservation* R, int m , int L, int C=0)
{
		return 99;
}
int check(Reservation* R, int m , char L, int C) // 오류 (문자만 입력한 경우)
{
	if(L < 65 || L >68) // A~D 범위에 벗어난경우
		return 99;
	if(C<1 || C>9) // 1~9 범위에 벗어난경우
		return 99;

	int use = R[m].USE(L, C); // 입력된 자리 사용여부 확인
	if(use ==1) // 입력된 자리가 사용한 자리라면
		return 99; 
} // 99는 오류로 main에서 판정
