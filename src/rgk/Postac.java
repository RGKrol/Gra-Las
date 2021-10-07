package rgk;

public class Postac {
    public char gender;
    private int positionCurrent, positionOld;

    public Postac (){  //konstruktor bezargumentowy
        positionCurrent = positionOld = 0;
    }
                //ustawienie nowej pozycji gracza
    public void setPozycja (int newGamerPossition){
        this.positionOld = this.positionCurrent;
        this.positionCurrent = newGamerPossition;
    }


    public int getPlayerPositionCurrent(){  return this.positionCurrent;}   //podaje aktualną pozycję gracza
    public int getPlayerPositionOld(){      return this.positionOld;}       //podaje poprzednią pozycję gracza

}
