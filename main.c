//
// Created by r3bers on 08.03.16.
//

//Ссылки на скачивание.
#define URL_FIRST "http://video.govoritmoskva.ru:8880/rufm_m.mp3"
#define URL_SECOND "http://gm.fmtuner.ru"

#include <stdio.h>
#include <curl/curl.h>
#include <pthread.h>
// include <errno.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fileName[250];
    char url[250];
    int time;
} ThreadArg;

void *download(void *arg) {
    ThreadArg *argument = arg;
    CURL *thcurl;
//    CURLcode thres;
    thcurl = curl_easy_init();
    if (thcurl) {
        curl_easy_setopt(thcurl, CURLOPT_TIMEOUT, argument->time);
        curl_easy_setopt(thcurl, CURLOPT_URL, argument->url);
        FILE *thf;
        thf = fopen(argument->fileName, "wb");
        curl_easy_setopt(thcurl, CURLOPT_WRITEDATA, thf);
//        thres =
        curl_easy_perform(thcurl);
        fclose(thf);
        curl_easy_cleanup(thcurl);
        printf("Thread: I am Finished!\n");
    }
    return NULL;
}

int main() {
    int result;
    pthread_t thread1, thread2;
    ThreadArg arg2, arg1;

    // First Thread Init
    strcpy(arg1.fileName, "first.mp3");
    strcpy(arg1.url, URL_FIRST);
    arg1.time = 10;

    //Second Thread Init
    strcpy(arg2.fileName, "second.mp3");
    strcpy(arg2.url, URL_SECOND);
    arg2.time = 20;

    //Let's go start two threads with downloading
    result = pthread_create(&thread1, NULL, download, &arg1);
    if (result != 0) {
        perror("Creating the first thread");
        //return EXIT_FAILURE;
    }
    result = pthread_create(&thread2, NULL, download, &arg2);
    if (result != 0) {
        perror("Creating the second thread");
        //return EXIT_FAILURE;
    }
    printf("Done Starting\n");
    pthread_join(thread1, NULL);
    printf("Thread One ended! \n");
    pthread_join(thread2, NULL);
    printf("Thread Two ended! \n");

    return EXIT_SUCCESS;
//    return 0;
}
