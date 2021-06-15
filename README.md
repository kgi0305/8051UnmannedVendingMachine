# 8051UnmannedVendingMachine
1. 음식점 무인 판매기를 만든 이유
최근 많은 음식점들이 증가하는 인건비 때문에 무인 판매기를 많이 설치하는 것을 보고 만들게 되었습니다. (EX 학식)
2. 기능
LCD, 7SEG, 8개의 버튼을 이용하여 만들었습니다.
P1.7~P1.4 4개의 버튼은 음식이름과 가격이 출력되게 합니다. 돈을 넣은 후에는 4개의 버튼을 누르면 음식을 구매하게 됩니다.
AD3, AD2, AD1은 각각 100원, 500원 1000원을 뜻하며 버튼을 누르면 7SEGMETN에 입력 됩니다.
AD0를 누르게 되면 남은돈을 반환합니다. 버튼을 누를시 “RETURN MONEY”가 출력되며 7SEGMENT의 값이 0이됩니다.
돈이 모자랄시에는 “NOT ENOUGH MONEY”가 출력됩니다.

전원을 켰을 때 ”choose a food”출력
![image](https://user-images.githubusercontent.com/83354402/122137033-b6064f00-ce7e-11eb-8f82-05984fdec007.png)

P1.7키를 눌렀을 때 돈까스와 가격이 출력
![image](https://user-images.githubusercontent.com/83354402/122137060-c0c0e400-ce7e-11eb-9d03-338b0471ce45.png)

P1.6키를 눌렀을 때 비빔밥과 가격이 출력
![image](https://user-images.githubusercontent.com/83354402/122137068-c6b6c500-ce7e-11eb-98dc-0dddf3bd526e.png)

P1.5키를 눌렀을 때 라면과 가격이 출력
![image](https://user-images.githubusercontent.com/83354402/122137078-cb7b7900-ce7e-11eb-87e3-4e9075071c80.png)

P1.4키를 눌렀을 때 김밥과 가격 출력
![image](https://user-images.githubusercontent.com/83354402/122137093-d1715a00-ce7e-11eb-9ee9-1a3343fd935b.png)

AD3키를 눌렀을 때 7SEGMENT에 돈이 출력
![image](https://user-images.githubusercontent.com/83354402/122137105-d6360e00-ce7e-11eb-8f34-bca09d3d8cbb.png)

AD2키를 눌렀을때
![image](https://user-images.githubusercontent.com/83354402/122137114-dc2bef00-ce7e-11eb-8733-ccb89459b2ff.png)

AD1키를 눌렀을 때
![image](https://user-images.githubusercontent.com/83354402/122137120-e0f0a300-ce7e-11eb-8ea2-e26b85cb8df9.png)

돈을 넣고 돈까스를 선택
![image](https://user-images.githubusercontent.com/83354402/122137139-ebab3800-ce7e-11eb-8cfd-086de0b634ea.png)
![image](https://user-images.githubusercontent.com/83354402/122137142-eea62880-ce7e-11eb-9b02-42c268936bdc.png)

돈이 부족할 때
![image](https://user-images.githubusercontent.com/83354402/122137155-f534a000-ce7e-11eb-9aa3-bed5bca381e9.png)

