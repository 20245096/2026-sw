#include <stdio.h>
#include <string.h>

#define BUCKET_SIZE (10)  // 해시 테이블 크기 (버킷 개수 = 10)

const char* samples[] = {"서울", "부산", "대구","인천", "광주", "대전", "울산", "세종", "경기", "강원", "충북","충남", "전북", "전남", "경북", "경남", "제주"};
                        // 해시 함수에 넣을 문자열 데이터들 (총 17개, 하지만 실제로는 앞의 10개만 사용됨)
int hashCode(const char* str);   // 해시 함수 선언

int main() {
	int hashTable[BUCKET_SIZE];    // 해시 테이블 배열 선언 (크기 10)

	for (int i = 0; i < BUCKET_SIZE; i++) {    // 0부터 9까지 반복
		hashTable[i] = 0;    // 각 인덱스를 0으로 초기화
	}

	for (int i = 0; i < BUCKET_SIZE; i++) {    // samples 배열의 앞 10개만 사용
		const char* source = samples[i];     // 현재 문자열을 source에 저장
		int hashAddress = hashCode(source);    // 문자열을 해시 함수에 넣어 주소 생성
		hashTable[hashAddress]++;    // 해당 주소 위치의 값을 1 증가 (충돌 시 누적됨)
		printf("%s --> %d\n", source, hashAddress);    // 문자열과 해시 주소 출력
	}

	for (int i = 0; i < BUCKET_SIZE; i++) {    // 해시 테이블 전체 출력
		printf("%d; %d\n",i, hashTable[i]);    // 인덱스와 해당 위치에 저장된 개수 출력
	}

	getchar();
	return 0;
}

int hashCode(const char* str) {    // 문자열을 입력받아 해시값을 반환하는 함수
	int hash = 0;    // 해시값 초기화

	for (int i = 0; i < strlen(str); i++) {
		hash = (hash * 10) + (int)(str[i]);    // 기존 hash에 10을 곱하고 현재 문자의 아스키 값을 더함
	}
	if (hash < 0) hash *= -1;    // 오버플로우로 음수가 되면 양수로 변환
	return (hash%BUCKET_SIZE);    // 10으로 나눈 나머지 → 0~9 사이 값 반환 (버킷 인덱스)
}
