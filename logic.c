logic()
{
	int j, randPass;

//	����
	vuser_init();
	
//	10 ��� ������� �����
	for (j = 1; j <= 10; j++){
		randPass = 1 + rand()%10;
		createTicket(randPass);
  	}
	
//	����������
	sort();
	
//	�����
	vuser_end();

	return 0;
}
