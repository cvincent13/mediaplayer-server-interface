//
// main.cpp
// Created on 21/10/2018
//

#include "database.h"
#include "film.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include "tcpserver.h"

using namespace std;
const int PORT = 3331;

#define VERSION_SERVEUR

#ifdef VERSION_SANS_SERVEUR

int main(int argc, const char* argv[])
{
    MediaPtr m1 = std::make_shared<Photo>();
    MediaPtr m2 = std::make_shared<Video>("video1", "../medias/video.mp4", 12);
    MediaPtr m3 = std::make_shared<Photo>("photo2", "../medias/photo2.png", 1.3, 5.3);

    MediaPtr tab[] = {m1, m2, m3};

    for (int k = 0; k < 3; k++) {
        tab[k]->display(std::cout);
    }

    int * ch = new int[4];
    ch[0]=4; ch[1]=6; ch[2]=3; ch[3]=9;
    FilmPtr f = std::make_shared<Film>("film1", "../medias/video.mp4", 4, ch, 4);

    delete[] ch;
    f->display(std::cout);
    f->displayChapters(std::cout);

    Group * g = new Group();
    g->push_back(m1);
    g->push_back(m2);
    g->push_back(m3);

    Group * g2 = new Group();
    g2->push_back(f);
    g2->push_back(m2);

    g->display(std::cout);
    delete g;
    g2->display(std::cout);

    return 0;
}

#endif

#ifdef VERSION_SERVEUR
int main(int argc, char* argv[])
{

    // Base de données contenant des médias
    Database * db = new Database;
    MediaPtr p1 = db->createPhoto(
      "photo1", "../medias/photo1.png", 1, 1
    );
    MediaPtr p2 = db->createPhoto(
      "photo2", "../medias/photo2.png", 2, 2
    );
    MediaPtr p3 = db->createPhoto(
      "photo3", "../medias/photo3.png", 3, 3
    );
    db->createVideo("video1", "../medias/video.mp4", 4);
    int * ch = new int[4];
    ch[0]=4; ch[1]=6; ch[2]=3; ch[3]=9;
    db->createFilm("film1", "../medias/video.mp4", 4, ch, 4);
    GroupPtr g1 = db->createGroup("photo_group");
    g1->push_back(p1);
    g1->push_back(p2);
    g1->push_back(p3);

    // cree le TCPServer
    auto* server =
            new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        std::stringstream ssRequest(request);
        std::string requestType, name;
        std::stringstream ssResponse;
        ssRequest >> requestType >> name;

        if (requestType == "displayGroup") {
            db->displayGroup(ssResponse, name);
            response = ssResponse.str();
        }

        else if (requestType == "displayMedia") {
            db->displayMedia(ssResponse, name);
            response = ssResponse.str();
        }

        else if (requestType == "play") {
            db->playMedia(ssResponse, name);
            response = ssResponse.str();
        }

        else {
            response = "Unknown request";
        }

            // the response that the server sends back to the client
            std::cout << "response: " << response << std::endl;

            // return false would close the connecytion with the client
            return true;
});


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

#endif
