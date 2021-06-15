# 8051UnmannedVendingMachine
1. 음식점 무인 판매기를 만든 이유

최근 많은 음식점들이 증가하는 인건비 때문에 무인 판매기를 많이 설치하는 것을 보고 만들게 되었습니다. (EX 안동대 학식)

2. 기능
LCD, 7SEG, 8개의 버튼을 이용하여 만들었습니다.
P1.7~P1.4 4개의 버튼은 음식이름과 가격이 출력되게 합니다. 돈을 넣은 후에는 4개의 버튼을 누르면 음식을 구매하게 됩니다.
AD3, AD2, AD1은 각각 100원, 500원 1000원을 뜻하며 버튼을 누르면 7SEGMETN에 입력 됩니다.
AD0를 누르게 되면 남은돈을 반환합니다. 버튼을 누를시 “RETURN MONEY”가 출력되며 7SEGMENT의 값이 0이됩니다.
돈이 모자랄시에는 “NOT ENOUGH MONEY”가 출력됩니다.