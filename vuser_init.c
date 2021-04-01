vuser_init()
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
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=49", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		LAST);
	return 0;
}
