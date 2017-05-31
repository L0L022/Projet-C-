#include "formes.hpp"

using namespace std;

Formes::Formes(size_t taille): maxformes(taille), nbformes(0), formes(nullptr)
{
  formes = new Forme* [maxformes];
}

Formes::~Formes()
{
  for(size_t i=0; i<nbformes; ++i)
  {
    delete formes[i];
  }
  delete [] formes;
}

void Formes::dessiner(EZWindow & w)
{
  for(size_t i=0; i<nbformes; ++i)
  {
    formes[i]->dessiner(w);
  }
}

void Formes::ajouter(Forme *f)
{
  if (nbformes < maxformes)
  {
    formes[nbformes++]=f;
  }
  else
  {
    throw runtime_error("Impossible d'ajouter une nouvelle forme !");
  }
}

Forme* Formes::isOver(uint x, uint y)
{
  for(size_t i=0; i<nbformes; ++i)
  {
    if(formes[i]->isOver(x,y))
    {
      return formes[i];
    }
  }
  return nullptr;
}

ostream & operator << (ostream & os, const Formes & fs)
{
  for (size_t i = 0; i < fs.nbformes; i++)
  {
    os<< *fs.formes[i] << endl;
  }
  return os;
}

void Formes::sauver(ostream & os) const
{
  os << nbformes;
  os << *this;
}

void Formes::charger(iostream & is)
{
  for (size_t i=0; i<nbformes; ++i)
  {
    delete formes[i];
  }
  nbformes = 0;
  size_t nb=0;
  is >> nb;
  for(size_t i=0; i<nb;++i)
  {
    ajouter(Forme::charger(is));
  }
}
