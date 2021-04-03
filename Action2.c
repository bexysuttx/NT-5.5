Action2()
{
	int sort[100];
	int sortPrice[100];
	int i,j;
	char sortHandler[500];
	char sortPriceHandler[10000];
	
	char* word="A";
	
	
	web_reg_save_param_ex(
    "ParamName=noPass", 
    "LB/IC=<b>&nbsp;&nbsp;",
    "RB/IC= ",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=totalTicket", 
    "LB/IC=A total of ",
    "RB/IC= scheduled",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=priceFirstTicket", 
    "LB/IC=Total Charge: $ ",
    "RB/IC= <BR/> (CC: x-)",
    "Ordinal=all",
	LAST);
	
	web_url("welcome.pl", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	//»нициализаци€ массивов дл€ дальнейшей обработки(ћассивов чисел и номера билета)
		for (i=0;i<atoi(lr_eval_string("{totalTicket_1}"));i++) {
		sprintf(sortHandler, "{noPass_%d}", i+1);
		sprintf(sortPriceHandler, "{priceFirstTicket_%d}", i+1);
		if (strcmp(lr_eval_string(sortHandler), word) == 0) {
			lr_output_message("WORD A DETECTED %s",lr_eval_string(sortHandler));
			sort[i]=1;
			sortPrice[i]=atoi(lr_eval_string(sortPriceHandler));
		} else {
				
				sort[i]=atoi(lr_eval_string(sortHandler));
				sortPrice[i]=atoi(lr_eval_string(sortPriceHandler));
		}
	}
	
	//проверка инициализации массивов
	for (i=0;i<10;i++) {
		lr_output_message("count passenger+++ %d",sort[i]);
		lr_output_message("price+++ %d",sortPrice[i]);
	}
	

    //сортировка
   for(i = 0 ; i < atoi(lr_eval_string("{totalTicket_1}"))-1; i++) { 
     
       for(j = 0 ; j < atoi(lr_eval_string("{totalTicket_1}")) - i - 1 ; j++) {  
           if(sort[j] > sort[j+1]) {           
           
              int tmp = sort[j];
              sort[j] = sort[j+1] ;
              sort[j+1] = tmp;
              tmp = sortPrice[j];
              sortPrice[j]=sortPrice[j+1];
              sortPrice[j+1]=tmp;
            
           }
        }
    }
    
    //¬ывод в консоль массивов
       for(i = 0 ; i < atoi(lr_eval_string("{totalTicket_1}")); i++) { 
    	lr_output_message("No passager:%d - Ticket Price - $ %d",sort[i],sortPrice[i]);
    }
	
	
	web_url("SignOff Button", 
		"URL={Host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	return 0;
}
