logic()
{
	int i, j, countLog, minFirstClass[3], numberMinFirstClass[3], randomUser1,randomUser2,randomUser3;
    char separators[] = "\n";
    char *token;
    char *logins[100], *passes[100], *log, *pas;

//	подготовительна€ часть: заходим под 3 пользовател€ми
    lr_read_file("login.dat", "l", 0);
    token = (char *)strtok(lr_eval_string("{l}"),separators);
	i = 0;
    while (token != NULL ) {
		token[strlen(token) - 1] = 0;
		logins[i] = token;
		token = (char *)strtok(NULL, separators);
        ++i;
    }
	countLog = --i;
	
    lr_read_file("pass.dat", "p", 0);
    token = (char *)strtok(lr_eval_string("{p}"),separators);
	i = 0;
    while (token != NULL ) {
		token[strlen(token) - 1] = 0;
		passes[i] = token;
		token = (char *)strtok(NULL, separators);
        ++i;
    }
	
	randomUser1 = rand()%countLog + 1;
	login1 = logins[randomUser1];
	pass1 = passes[randomUser1];
	lr_output_message("ѕервый случайный пользователь %s с паролем %s",login1,pass1);

	randomUser2 = rand()%countLog + 1;
	while(randomUser2 == randomUser1) {
		randomUser2 = rand()%countLog + 1;
	}
	login2 = logins[randomUser2];
	pass2 = passes[randomUser2];
	lr_output_message("ѕервый случайный пользователь %s с паролем %s",login2,pass2);

	randomUser3 = rand()%countLog + 1;
	while((randomUser3 == randomUser1) || (randomUser3 == randomUser2)) {
		randomUser3 = rand()%countLog + 1;
	}
	login3 = logins[randomUser3];
	pass3 = passes[randomUser3];
	lr_output_message("ѕервый случайный пользователь %s с паролем %s",login3,pass3);
	
//	первый случайный пользователь
	vuser_init(login1,pass1);
	for (j = 1; j<=10; j++){
		createTicket();
  	}
	vuser_end();

//	второй случайный пользователь
	vuser_init(login2,pass2);
	for (j = 1; j<=10; j++){
		createTicket();
  	}
	vuser_end();

//	третий случайный пользователь
	vuser_init(login3,pass3);
	for (j = 1; j<=10; j++){
		createTicket();
  	}
	vuser_end();

//	¬ыполнение задачи
//	¬ход и подсчет количества билетов первого класса дл€ кадого пользовател€
//	randomUser1
	vuser_init(login1,pass1);
	count[1] = checkFirstClass();
	vuser_end();

//	randomUser2
	vuser_init(login2,pass2);
	count[2] = checkFirstClass();
	vuser_end();

//	randomUser3
	vuser_init(login3,pass3);
	count[3] = checkFirstClass();
	vuser_end();
	
	j = 1;
	minFirstClass[j] = count[1];
	numberMinFirstClass[j] = 1;
	lr_output_message(" оличество билетов первого класса пользовател€ %s равно %d",login1,count[1]);
	lr_output_message(" оличество билетов первого класса пользовател€ %s равно %d",login2,count[2]);
	lr_output_message(" оличество билетов первого класса пользовател€ %s равно %d",login3,count[3]);
	for(i = 2; i <= 3; i++) {
		if (count[i] < minFirstClass[j]) {
			j = 1;
			minFirstClass[j] = count[i];
			numberMinFirstClass[j] = i;
		}
		else {
			if (count[i] == minFirstClass[j]) {
				j++;
				minFirstClass[j] = count[i];
				numberMinFirstClass[j] = i;
			}
		}
	}
	
	i = rand()%j + 1;

	switch(numberMinFirstClass[i]) {
		case 1: log = login1;
				pas = pass1;
				lr_output_message("”дал€ем у пользователс€ %s", login1);				
        	break;
    	case 2: log = login2;
				pas = pass2;
				lr_output_message("”дал€ем у пользователс€ %s", login2);
	        break;
        case 3: log = login3;
				pas = pass3;
				lr_output_message("”дал€ем у пользователс€ %s", login3);
	        break;
    }

//	¬ход
	vuser_init(log,pas);
	
//	Itinerary => удаление случайного билета
	checkAndDel(minFirstClass[i]);
	
//	¬ыход
	vuser_end();

	return 0;
}
