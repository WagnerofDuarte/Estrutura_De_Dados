#ifndef PONTO
#define PONTO

class Ponto {

    private:
        int x;
        int y;
        double distancia;

    public:

        Ponto(int _x, int _y);

        void setDistancia(double _distancia);
        double getDistancia();

        int getX();
        int getY();

};

#endif