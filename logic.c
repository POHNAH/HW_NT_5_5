logic()
{
	int j, randPass;

//	вход
	vuser_init();
	
//	10 раз создаем билет
	for (j = 1; j <= 10; j++){
		randPass = 1 + rand()%10;
		createTicket(randPass);
  	}
	
//	сортировка
	sort();
	
//	выход
	vuser_end();

	return 0;
}
