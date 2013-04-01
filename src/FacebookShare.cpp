/*
 * FacebookShare.cpp
 *
 */

#include "FacebookShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include <curl/curl.h>
#include "ShareResponseStatusEvent.hpp"
#include "ShareEventBus.hpp"

FacebookShare::FacebookShare(){

}

FacebookShare::~FacebookShare(){

}

void FacebookShare::share(std::string data){
	  CURL *curl;
	  CURLcode res;

	  /* In windows, this will init the winsock stuff */
	  curl_global_init(CURL_GLOBAL_ALL);

	  /* get a curl handle */
	  curl = curl_easy_init();
	  if(curl) {
	    /* First set the URL that is about to receive our POST. This URL can
	       just as well be a https:// URL if that is what should receive the
	       data. */
	    curl_easy_setopt(curl, CURLOPT_URL, "https://graph.facebook.com/me/drinkitapp:make");
	    /* Now specify the POST data */
	    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "access_token=AAAImC5A4sygBAGdZCFRZBgOy8ZAXKbHU0CccciSVWp4zTXmBqwYpqp1kt0MZC4ZCd3p20Yl3h6m0qHxD0ubDAKremoT201sZB0uw30lHyGIwZDZD&method=POST&drink=http://samples.ogp.me/604782039551942");
	    /* Perform the request, res will get the return code */
	    res = curl_easy_perform(curl);
	    /* Check for errors */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() failed: %s\n",
	              curl_easy_strerror(res));

	    /* always cleanup */
	    curl_easy_cleanup(curl);
	    ShareResponseStatusEvent *e = new ShareResponseStatusEvent(ShareResponseStatusEvent::SUCCESS);
	    ShareEventBus::FireEvent(e);
	  }
	  curl_global_cleanup();

}

void FacebookShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}
// TODO not sure what the RequestRecipes function returns, leaving it out for now
