createTicket()
{

web_reg_save_param_ex(
    "ParamName=userSession", 
    "LB/IC=name=\"userSession\" value=\"",
    "RB/IC=\"",
    "Ordinal=1",
	LAST);
	

	web_url("webtours", 
		"URL={Host}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");



	web_submit_data("login.pl",
		"Action={Host}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer={Host}/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=westy", ENDITEM,
		"Name=password", "Value=westy", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=49", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		LAST);

	

	web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

web_reg_save_param_ex(
    "ParamName=OFlight", 
    "LB/IC=name=\"outboundFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal=1",
	LAST);

	web_submit_data("reservations.pl", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={City}", ENDITEM, 
		"Name=departDate", "Value={DateDepart}", ENDITEM, 
		"Name=arrive", "Value={City2}", ENDITEM, 
		"Name=returnDate", "Value={DateArrive}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=37", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);



	web_submit_data("reservations.pl_2", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=51", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);



	web_submit_data("reservations.pl_3", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Address}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={OFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=58", ENDITEM, 
		"Name=buyFlights.y", "Value=7", ENDITEM, 
		LAST);

	
	return 0;
}
