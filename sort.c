sort()
{
	int i,j,k, count, passInTicket, index[100];
	char paramName[100];
	
	lr_output_message("-----------------------------------------");
	lr_output_message("-----------------------------------------");
	lr_output_message("����������");
	lr_output_message("-----------------------------------------");
	lr_output_message("-----------------------------------------");

//	������� � Itinerary
	web_reg_save_param_ex(
	    "ParamName=flightIDs", 
	    "LB/IC=name=\"flightID\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=all");
	
	web_reg_save_param_ex(
		"ParamName=countPass",
		"LB=<b>&nbsp;&nbsp;",
		"RB= ",
		"Ordinal=all",
		LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

    count = atoi(lr_eval_string("{countPass_count}"));
    
//  ���������� ���� ��������. �� 1 �� 10 ���, �������� �� ���� ������� ���� ���������� ���������� ����� i 
//	�� ������ �������� � ������ �������� ����� ������� ������� ������ �������� ���������������� �������
//	����� ������ ������ ���������� ��������� ������������ �������
	k = 0;
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= count; j++) {
    		sprintf(paramName, "{countPass_%d}", j);
    		
    		if (strcmp(lr_eval_string(paramName),"A") == 0) {
				passInTicket = 1;
		    }
		    else {
		    	passInTicket = atoi(lr_eval_string(paramName));
		    }
    		
    		if (passInTicket == i) {
    			++k;
    			index[k] = j;
    		}
    	}
	}
	
//	������� ��������������� ������ � �� flightID
    for (i = 1; i <= count; i++) {
		sprintf(paramName, "{countPass_%d}", index[i]);
		if (strcmp(lr_eval_string(paramName),"A") == 0) {
			passInTicket = 1;
	    }
	    else {
	    	passInTicket = atoi(lr_eval_string(paramName));
	    }
		
		sprintf(paramName, "{flightIDs_%d}", index[i]);
		lr_output_message("����� � ID %s �� %d ����.", lr_eval_string(paramName), passInTicket);
    }

	return 0;
}
