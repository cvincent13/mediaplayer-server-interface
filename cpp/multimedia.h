#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

/*!
 * \file multimedia.h
 * \brief Classe de base dans l'héritage
 * \author Vincent_Cedric
 */
#include <string>
#include <ostream>


/*! \class Multimedia
   * \brief Classe de base des médias
   *
   *  Classe abstraite représentant les différents médias à afficher
   */
class Multimedia
{
private:
    std::string name{}; /*!< Nom du média*/

    std::string pathname{}; /*!< Adresse du fichier*/

public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Multimedia sans paramètres
     *
     */
    Multimedia();

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Multimedia
     *
     *  \param name : nom du média
     *  \param pathname : adresse du média
     */
    Multimedia(std::string name, std::string pathname);

    /*!
     *  \brief Modifieur de name
     *
     *  Modifie le nom de l'objet
     *
     *  \param name : nouveau nom
     */
    void setName(std::string name);

    /*!
     *  \brief Mofificateur de pathname
     *
     *  Modifie l'adresse de l'objet
     *
     *  \param pathname : nouvelle adresse
     */
    void setPathname(std::string pathname);

    /*!
     *  \brief Acesseur de name
     *
     *  Accède au nom de l'objet
     *
     *  \return name
     */
    std::string getName() const;

    /*!
     *  \brief Acesseur de pathname
     *
     *  Accède à l'adresse de l'objet
     *
     *  \return pathname
     */
    std::string getPathname() const;

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Multimedia
     */
    ~Multimedia();

    /*!
     *  \brief Affichage des informations de l'objet
     *
     *  Méthode virtuelle affichant les variables de l'objet
     *  sur un flux de sortie
     *
     *  \param s : flux de sortie
     */
    virtual void display(std::ostream & s) const;

    /*!
     *  \brief Joue l'objet
     *
     *  Méthode virtuelle jouant l'objet
     *
     */
    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H
