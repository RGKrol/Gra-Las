package rgk;

public class Postac {
    public char plec;
    private int pozycjaAktualna, pozycjaStara;

    public Postac (){  //konstruktor bezargumentowy
        pozycjaAktualna = pozycjaStara = 0;
    }

    public void setPozycja (int nowaPozycjaPostaci){
        this.pozycjaStara = this.pozycjaAktualna;
        this.pozycjaAktualna = nowaPozycjaPostaci;
    }
    public int pokazPozycjeAktualna(){  return this.pozycjaAktualna;}
    public int pokazPozycjeStara(){     return this.pozycjaStara;}

}
