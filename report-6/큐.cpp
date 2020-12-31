#include<iostream>

using namespace std;


class BaseArray {
private:
	int capacity; // ���� �Ҵ�� �޸� �뷮
	int* mem;
protected:
	BaseArray(int capacity) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};



class MyQueue : BaseArray {
private:
	//����ť�� index�� 2����, �����ϸ鼭 ����� real ���鼭 ����� front
	int front, real;
public:
	//�ڽĻ����� ȣ��� �θ� �����ڵ� ȣ�� Java�� Super
	MyQueue(int capacity) : BaseArray(capacity) {
		//���� ť�� front, real �� index 0���� ����
		this->front = 0;
		this->real = 0;
	}

	bool is_full() {
		//����ť�� real+1 % Capacity �� front �Ͻ� ����
		if ((real + 1) % getCapacity() == front) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_empty() {
		//front�� real�� index�� ���ٸ� �������
		if (front == real) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(int item) {
		//���� ������ �ʾҴٸ�
		if (!is_full()) {
			//real�� ���� +1%Capacity index�� ����, %Capacity�� �ؾ� �������� index���� ���� �� ����
			real = (real + 1) % getCapacity();
			//�θ� Ŭ������ putȣ��, index�� real%Capacity, �׸��� item ����
			put(this->real % getCapacity(), item);
		}
		else {
			cout << "Queue is full" << endl;
		}
	}

	int dequeue() {
		//�þ� ������� �ʴٸ�
		if (!is_empty()) {
			//�� ���� front�� ������° index ������ ����ť�̹Ƿ� index����-> %Capacity �� ���� ����
			int value = get((front + 1) % getCapacity());
			//front�� ���� +1 ���ְ�, %Capacity��ŭ ������
			front = (front + 1) % getCapacity();
			//���� Retrun
			return value;
		}
		else {
			cout << "Queue is empty" << endl;
		}
	}
};

/*
int main() {
	MyQueue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.dequeue() << endl;
	q.enqueue(4);
	q.enqueue(5);
	while (!q.is_empty()) {
		cout << q.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	return 0;
} 
*/



int main() {
	MyQueue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	while (!q.is_empty()) {
		cout << q.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	return 0;
}