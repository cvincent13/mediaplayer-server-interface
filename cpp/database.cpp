#include "database.h"
#include <iostream>

Database::Database()
{
}

PhotoPtr Database::createPhoto(std::string name, std::string path,
                               float latitude, float longitude) {
    PhotoPtr photo = std::make_shared<Photo>(name, path, latitude, longitude);
    mediaTable[name] = photo;
    return photo;
}

VideoPtr Database::createVideo(std::string name, std::string path,
                               int duration) {
    VideoPtr video = std::make_shared<Video>(name, path, duration);
    mediaTable[name] = video;
    return video;
}

FilmPtr Database::createFilm(std::string name, std::string path,
                             int duration, int * chapters, int chapters_number) {
    FilmPtr film = std::make_shared<Film>(name, path, duration, chapters, chapters_number);
    mediaTable[name] = film;
    return film;
}

GroupPtr Database::createGroup(std::string name) {
    GroupPtr group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void Database::displayMedia(std::ostream & s, std::string name) {
    auto media = mediaTable.find(name);
    if (media != mediaTable.end()) {
        media->second->display(s);
    } else {
        s << "Media not found.";
    }
}

void Database::playMedia(std::ostream & s, std::string name) {
    auto media = mediaTable.find(name);
    if (media != mediaTable.end()) {
        media->second->play();
        s << "Playing media on server";
    } else {
        s << "Media not found.";
    }
}

void Database::displayGroup(std::ostream & s, std::string name) {
    auto group = groupTable.find(name);
    if (group != groupTable.end()) {
        group->second->display(s);
    } else {
        s << "Group not found.";
    }
}
