// !  Tayyab_Kamran_Sami_22i_2505

#include <iostream>
using namespace std;

class Creature
{
protected:
  const string Name;
  int Level;
  int HealthPoints;
  int Force;
  int PositionM;

public:
  // Constructor for Creature
  Creature(const string name, int level, int healthpoints, int force, int position = 0) : Name(name)
  {
    this->Level = level;
    this->HealthPoints = healthpoints;
    this->Force = force;
    this->PositionM = position;
  }

  // Getter for Position
  int position()
  {
    return this->PositionM;
  }

  // Getter for Health points
  int GetHealthPoints()
  {
    return this->HealthPoints;
  }

  // Setter for Health points
  void SetHealthPoints(int H)
  {
    this->HealthPoints = H;
  }

  bool alive()
  {
    if (this->HealthPoints > 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int AttackPoints()
  {
    if (alive())
    {
      return this->Level * this->Force;
    }
    else
    {
      return 0;
    }
  }

  void Move(int pos)
  {
    this->PositionM += pos;
  }

  void GoodBye()
  {
    cout << this->Name << " is no more!";
  }

  void Weak(int val)
  {

    if (alive())
    {
      this->HealthPoints -= val;

      if (!alive())
      {
        this->HealthPoints = 0;
        GoodBye();
      }
    }
  }

  void display()
  {
    cout << this->Name << ", level: " << this->Level << ", health_status: " << this->HealthPoints << ", force: " << this->Force << ", Attacking points: " << AttackPoints() << ", position: " << this->PositionM << " \n";
  }
};

class Dragon : public Creature
{
protected:
  int FlameRange;

public:
  // Constructor for Dragon, initializing the values by running the running the parameterized construcotr of base class
  Dragon(const string name, int level, int Hp, int force, int FR, int position = 0) : Creature(name, level, Hp, force, position)
  {
    this->FlameRange = FR;
  }

  void Fly(int pos)
  {
    this->PositionM = pos;
  }

  void BlowFlame(Creature &obj)
  {
    // Check 1 --> If both are Alive
    if ((obj.alive()) && (this->alive()))
    {
      int X = obj.position() - this->PositionM;
      int Y = this->PositionM - obj.position();

      // Check 2 --> If both are in Range
      if ((X <= this->FlameRange) || (Y >= this->FlameRange))
      {
        obj.Weak(this->AttackPoints());

        if ((abs(this->PositionM - obj.position())) > 0)
        {
          this->Weak(abs(this->PositionM - obj.position()));
        }

        if (!obj.alive())
        {
          this->Level++;
        }
      }
    }
  }
};

class Ichneumon : public Creature
{
protected:
  int NeckLength;
  int PoisonDose;

public:
  // Constructor for Dragon, initializing the values by running the running the parameterized construcotr of base class
  Ichneumon(const string name, int level, int hp, int force, int Neck, int poison, int pos = 0) : Creature(name, level, hp, force, pos)
  {
    this->NeckLength = Neck;
    this->PoisonDose = poison;
  }

  void InjectPoison(Creature &obj)
  {
    // Check 1 --> If both are Alive 
    if ((obj.alive()) && (this->alive()))
    {
      // Check 2 --> If both are in Range 
      if (((obj.position() - this->PositionM) >= this->NeckLength) || ((this->PositionM - obj.position()) <= this->NeckLength))
      {
        obj.Weak(this->AttackPoints() + this->PoisonDose);

        if ((abs(this->PositionM - obj.position())) > 0)
        {
          this->Weak(abs(this->PositionM - obj.position()));
        }

        if (!obj.alive())
        {
          this->Level++;
        }
      }
    }
  }
};

void Fight(Dragon &obj1, Ichneumon &obj2)
{
  // Both Fight by using their specific skills 
  obj2.InjectPoison(obj1);
  obj1.BlowFlame(obj2);
}

/*-------------------------Main----------------------------------*/
int main()
{
  Dragon dragon("Dragon red", 2, 10, 3, 20);
  Ichneumon ichneumon("ichneumon evil", 2, 10, 1, 10, 1, 42);

  dragon.display();
  cout << "is preparing for fight with :" << endl;
  ichneumon.display();

  cout << endl;
  cout << "1st Fight :" << endl;
  cout << "    the creature-s are not within range, so can not Attacke."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon has flown close to ichneumon :" << endl;
  dragon.Fly(ichneumon.position() - 1);
  dragon.display();

  cout << endl;
  cout << "ichneumon moves :" << endl;
  ichneumon.Move(1);
  ichneumon.display();

  cout << endl;
  cout << "2nd Fight :" << endl;
  cout << ""
       << "+ ichneumon inflicts a 3-point attack on dragon\n"
          " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
          "+ Dragon inflicts a 6-point attack on ichneumon\n"
          "[ level (2) * force (3) = 6 ] ;\n"
          "+ during his attack, dragon loses two additional points\n"
          "      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon moves by one step " << endl;
  dragon.Move(1);
  dragon.display();

  cout << endl;
  cout << "3rd Fight :" << endl;
  cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
          "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
          "+ Dragon inflicts a 6-point attack on ichneumon \n "
          "      [ level (2) * force (3) = 6 ] ; \n"
          "+ during his attack, dragon lost 1 additional life point.\n"
          "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
          "+ ichneumon is defeated and the dragon rises to level 3"
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "4th Fight :" << endl;
  cout << "    when one creatures is defeated, nothing happpens" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  return 0;
}
