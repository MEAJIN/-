#include<iostream>

using namespace std;

class SortedArray {
	int* p;   // �迭�� ���� ������
	int size; // �迭 ũ��

public:
	SortedArray() {  
		p = NULL; // p�� NULL�� �ʱ�ȭ ��Ų��.
		size = 0; // size�� 0���� �ʱ�ȭ �����ش�.
	}

	SortedArray(int a[], int size){
		p = a;             // p�� �̸� ����Ű�� �ϰ�, a�� �ش� �迭�� �����Ѵ�.
		this->size = size; // size ũ���� ���� �迭 �Ҵ� ��,
	}

	~SortedArray() { // �Ҹ���
		cout << "�Ҹ���" << endl;
	}

	void show(); // �迭�� ���Ҹ� ������� ���

	friend SortedArray operator + (SortedArray a, SortedArray b); // SortedArray ��ü�� ���ϴ� ������ => a+b
};
void SortedArray::show() {
	cout << "�迭 ��� : ";

	for (int i = 0; i < size;i++) {    // �迭�� ��� �ִ� ���� ���Ͽ� ������������ ����
		cout << p[i] << " ";
	}
	cout << endl;
}

SortedArray operator + (SortedArray a, SortedArray b) {

	SortedArray tmp;
	tmp.size = a.size + b.size; // a �� b �� �迭 ũ�⸦ ���� tmp �迭 ũ��� �Ҵ�
	int* tmp_array = (int*)malloc(sizeof(int) * tmp.size); // a �� b�� ���� �迭 ũ�⸦ �����Ҵ�
	tmp.p = tmp_array; // �Ҵ� �� �迭�� ��ü p�� �Ҵ�
	
	int i = 0, j = 0, index = 0; // �� �迭���� ���� �ε���

	while (i < a.size && j < b.size) {  // �迭 a�� ũ�Ⱑ i ���� ũ�鼭 �迭 b�� ũ�Ⱑ j���� Ŭ������ while �� �ݺ�

		if (a.p[i] < b.p[j]) {         // ����, �迭 a�� ���� �迭 b�� �� ���� �������
			tmp.p[index++] = a.p[i++]; // tmp��ü�� p�� index ��°�� a�� p�迭�� i��° ���� �Ҵ�
		}

		else {                         // ���� �׷��� ���� ���
			tmp.p[index++] = b.p[j++]; // tmp��ü�� p�� index ��°�� b�� p�迭�� j��° ���� �Ҵ�
		}
	}

	// a �Ǵ� b�� �迭�� ���� ������ ��� tmp�� ��ü�� �迭�� �Ҵ�
	if (i < a.size) {
		tmp.p[index++] = a.p[i++];
	}

	if (j < b.size) {				
		tmp.p[index++] = b.p[j++];  
	}
	return tmp;
}

int main() {

	// ������������ ���ĵ� �迭
	int p[] = { 2,6,20 };
	int q[] = { 7,8,10,20,30 };

	SortedArray a(p, 3), b(q, 5), c;

	c = a + b; // + ���� ���� �����, a �� b�� ���Ե� �迭 ������ �����ϸ鼭
			   // ������ �迭�� �����ϴ� SortedArray ��ü�� �����ϰ�, �̸� c�� �Ҵ����ش�.

	a.show(); // a�� ���Ե� �迭 ��Ҹ� ������� ���
	b.show(); // b�� ���Ե� �迭 ��Ҹ� ������� ���
	c.show(); // c�� ���Ե� �迭 ��Ҹ� ������� ���

	return 0;
}