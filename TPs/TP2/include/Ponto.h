#ifndef PONTO
#define PONTO

class Ponto {

    private:
        int x;
        int y;
        double angulo;

    public:

        Ponto(int _x, int _y);

        void setAngulo(double _angulo);
        double getAngulo();

        void calcularAngulo(Ponto* ponto_zero);

        int getX();
        int getY();

        void setX(int _x);
        void setY(int _y);

};

#endif