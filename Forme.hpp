#include <iostream>
#include "point.hpp"
#ifndef FORME_HPP
#define FORME_HPP
using namespace std;

typedef unsigned long ulong;
class Forme{
	private:
	   ulong couleur;
	   Point ancre;
	   bool selected;
	 protected:
	   virtual void ecrire(ostream & os) const;
	 public:
	   Forme (ulong couleur, uint x, uint y);
	   Forme (const Forme & orig);
	   Forme( iostream & is);
	   virtual ~Forme ();
	   inline ulong getCouleur() const {return couleur;};
	   inline void setCouleur( ulong couleur_){couleur= couleur_;};
	   inline Point getAncre()const {return ancre;};
	   inline void setAncre(uint x_, uint y_) {ancre.setxy(x_,y_);};//inline void setAncre (Point _ancre) {ancre= _ancre;};
	   inline bool isOver( uint _x, uint _y) {return ancre.isOver(_x, _y);};
	   virtual void dessiner (EZWindow & f, bool isActive= false)const;
	   void ecrire(ostream & os);
	   friend ostream & operator << (ostream & os, const Forme & forme);
	   virtual double perimetre() const = 0;
	   static Forme *charger(iostream & is);
};
#endif
