#include <iostream>
using namespace std;
class Gem
{
    int type; // 1: เพชร, 2: ทับทิม, 3: หยก, 4: ไพลิน, 5: มุก
    static int count;

public:
    Gem()
    {
        count++;
        setType(5);
        // cout << "count Obj = " << count << endl;
    }
    Gem(int t)
    {
        count++;
        setType(t);
        // cout << "count Obj = " << count << endl;
    }
    ~Gem()
    {
        count--;
        cout << "delete gem type = " << type << endl;
        // cout << "count Obj = " << count << endl;
    }

    // set
    void setType(int t)
    {
        if (t < 1 || t > 5)
        {
            cout << "no type " << endl;
            type = 0; // ถ้าส่ง type มาผิดจะถือว่าไม่มี type เลยให้ type = 0 ไว้
            return;
        }
        else
        {
            type = t;
        }
    }
    // get
    int getType()
    {
        return type;
    }
    // show
    void showGem()
    {
        cout << "\n---- show Gem ---- " << endl;
        cout << "Type gem is ";
        switch (type)
        {
        case 1:
            cout << "daimion ";
            break;
        case 2:
            cout << "pomegranate ";
            break;
        case 3:
            cout << "jade ";
            break;
        case 4:
            cout << "sapphire ";
            break;
        case 5:
            cout << "pearl ";
            break;

        default:
            break;
        }

        cout << endl;
    }

    // static เขียนเหมือน get
    static int countGem()
    {
        return count;
    }
};
int Gem::count;
// int /ชื่อclass :: /ชื่อ obj ที่เป็น static

class Jewelry
{
    double price;
    int madeFrom; // 1: ทอง, 2: เงิน, 3: ทองคำขาว

public:
    Jewelry()
    {
        setPrice(990.0);
        setMadeForm(2);
    }
    Jewelry(double p, int m)
    {
        setPrice(p);
        setMadeForm(m);
    }
    ~Jewelry()
    {
        cout << "delete Jewelry: price = " << price << " made from = " << madeFrom << endl;
    }

    // set
    void setPrice(double p)
    {
        if (p < 1)
        {
            cout << "price error " << endl;
        }
        else
        {
            price = p;
        }
    }
    void setMadeForm(int m)
    {
        if (m < 1 || m > 3)
        {
            cout << "made from error " << endl;
        }
        else
        {
            madeFrom = m;
        }
    }

    // get
    double getPrice()
    {
        return price;
    }
    int getMadeFrom()
    {
        return madeFrom;
    }

    // show
    void showJewelry()
    {
        cout << "\n---- show Jewelry ---- " << endl;
        cout << "Price " << price << " made from " << madeFrom << endl;
    }
};

class Ring : public Jewelry
{
    Gem **gems; // อาร์เรย์ของ pointer ที่ชี้ไปยัง Gem objects
    int num;    // ขนาดของอาร์เรย์ gems

public:
    Ring() : Jewelry(3000, 3)
    {
        setNum(0);
    }
    Ring(int n, double p, int m)
    {
        // base----------
        setPrice(p);
        setMadeForm(m);
        //--------------

        setNum(n); // จองพื้นที่
    }
    ~Ring()
    {
        // คืนพื้นที่ 2d
        /*if (gems != 0)
        {
            for (int i = 0; i < num; i++)
            {
                delete[] gems[i]; // ลบอ็อบเจกต์ที่ชี้ด้วยพอยน์เตอร์
            }
            delete[] gems; // ลบอาร์เรย์ gems
        }*/

        // คืนพื้นที่ 1d
        if (gems != 0)
        {
            delete[] gems;
        }
    }

    // set
    void setNum(int n)
    {
        // จองพื้นที่
        if (n >= 0)
        {
            num = n;
            gems = new Gem *[num]; // game[i] จองที่แค่มิติเดียว
        }
    }
    // setGems แบบที่จารต้องการแต่เราทำไม่ได้
    void setGems(int i, Gem *g)
    {
        gems[i] = g;
    }

    // get
    Gem *getGems(int i)
    {
        return gems[i];
    }
    int getNum()
    {
        return num;
    }

    // show
    void showRing()
    {
        cout << "\n---- show Ring ---- " << endl;
        cout << "detail gems in ring" << endl;
        cout << "Number of Gems: " << num << endl;
        cout << "price = " << Jewelry::getPrice() << endl;
        cout << "made from = " << Jewelry ::getMadeFrom() << endl;
    }

    //------------
    // bool
    bool isGem(int t)
    {
        for (int i = 0; i < num; i++)
        {

            if (gems[i]->getType() == t)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    //------------
};

class Necklace : public Jewelry
{
    bool pendant;

public:
    Necklace() : Jewelry(22000, 1)
    {
        setPandent(true);
    }
    Necklace(bool pd, double p, int m)
    {
        // base----------
        setPrice(p);
        setMadeForm(m);
        //--------------

        setPandent(pd);
    }
    ~Necklace()
    {
        cout << "delete nacklace pandent is " << pendant << endl;
    }

    // set
    void setPandent(bool pd)
    {
        pendant = pd;
    }

    // get
    bool getPandent()
    {
        return pendant;
    }

    // show
    void showPandent()
    {
        cout << "\n---- show Necklance ---- " << endl;
        if (pendant == 1)
        {
            cout << "have pandent " << endl;
        }
        else
        {
            cout << "don't have pandent " << endl;
        }
        cout << "price = " << Jewelry::getPrice() << endl;
        cout << "made from = " << Jewelry ::getMadeFrom() << endl;
    }
};

main()
{
    // สร้างอาร์เรย์ของ Gem ขนาด 8
    Gem g[8];
    g[0].setType(1); // เพชร
    g[1].setType(1); // เพชร
    g[2].setType(2); // ทับทิม
    g[3].setType(3); // หยก
    g[4].setType(4); // ไพลิน
    g[5].setType(5); // มุก
    g[6].setType(1); // เพชร
    g[7].setType(1); // เพชร

    cout << "----- Details ----- " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "g[" << i << "] type = " << g[i].getType() << endl;
    }

    // สร้างอาร์เรย์ของ Ring ขนาด 2
    Ring r[2];
    r[0].setNum(1);         // กำหนดจำนวนอัญมณีใน r[0]
    r[0].setGems(0, &g[5]); // ประดับไข่มุก g[5]
    r[0].setPrice(33000);
    r[0].setMadeForm(2); // เงิน
    r[0].showRing();

    r[1].setNum(3);         // กำหนดจำนวนอัญมณีใน r[1]
    r[1].setGems(0, &g[2]); // ทับทิม g[2]
    r[1].setGems(1, &g[0]); // เพชร g[0]
    r[1].setGems(2, &g[1]); // เพชร g[1]
    r[1].setPrice(150000);
    r[1].setMadeForm(1); // ทอง
    r[1].showRing();

    // สร้างอาร์เรย์ของ Necklace ขนาด 2
    Necklace n[2];
    n[0].setPrice(10000);
    n[0].setMadeForm(3);
    n[0].setPandent(true);

    cout << "\n----- get Necklace -----" << endl;
    if (n[0].getPandent() == 1)
    {
        cout << "have pandent " << endl;
    }
    else
    {
        cout << "don't have pandent " << endl;
    }
    cout << "Price = " << n[0].getPrice() << endl;
    cout << "Made from = " << n[0].getMadeFrom() << endl;

    n[1].setPrice(20000);
    n[1].setMadeForm(1);
    n[1].setPandent(0);

    cout << "\n----- get Necklace -----" << endl;
    if (n[1].getPandent() == 1)
    {
        cout << "have pandent " << endl;
    }
    else
    {
        cout << "don't have pandent " << endl;
    }
    cout << "Price = " << n[1].getPrice() << endl;
    cout << "Made from = " << n[1].getMadeFrom() << endl;

    // ราคารวม
    double total = r[0].getPrice() + r[1].getPrice() + n[0].getPrice() + n[1].getPrice();

    cout << "\n------- Total price -------" << endl;
    cout << "Ring      r[0] price = " << r[0].getPrice() << endl;
    cout << "Ring      r[1] price = " << r[1].getPrice() << endl;
    cout << "Neckleace n[0] price = " << n[0].getPrice() << endl;
    cout << "Neckleace n[1] price = " << n[1].getPrice() << endl;
    cout << "total----------------- " << total << endl;

    int glod = 0;
    glod += (r[0].getMadeFrom() == 1);
    glod += (r[1].getMadeFrom() == 1);
    glod += (n[0].getMadeFrom() == 1);
    glod += (n[1].getMadeFrom() == 1);
    cout << "Jewelry made from glod = " << glod << " piece" << endl; //

    // update r[0]
    r[0].setNum(3);         // กำหนดจำนวนอัญมณีใน r[0]
    r[0].setGems(0, &g[4]); // ประดับไพลิน g[4]
    r[0].setGems(1, &g[6]); // ประดับเพชร g[6]
    r[0].setGems(2, &g[7]); // ประดับเพชร g[7]
    r[0].setPrice(80000);
    r[0].setMadeForm(2); // เงิน
    // r[0].showRing();

    // get all Ring
    cout << "\n----- get Ring -----" << endl;
    cout << "detail gems in r[0]" << endl;
    cout << "Number of Gems: " << r[0].getNum() << endl;
    cout << "price = " << r[0].getPrice() << endl;
    cout << "made from = " << r[0].getMadeFrom() << endl;
    cout << "\ngems in r[0] : " << endl;
    Gem *gr00 = r[0].getGems(0);
    Gem *gr01 = r[0].getGems(1);
    Gem *gr02 = r[0].getGems(2);
    cout << "Add type = " << gr00 << " " << gr01 << " " << gr02 << endl;

    cout << "\ndetail gems in r[1]" << endl;
    cout << "Number of Gems: " << r[1].getNum() << endl;
    cout << "price = " << r[1].getPrice() << endl;
    cout << "made from = " << r[1].getMadeFrom() << endl;
    cout << "\ngems in r[1] : " << endl;
    Gem *gr10 = r[1].getGems(0);
    Gem *gr11 = r[1].getGems(1);
    Gem *gr12 = r[1].getGems(2);
    cout << "Add type = " << gr10 << " " << gr11 << " " << gr12 << endl;

    // isGem
    cout << "\n----- Ring have gems type 2 ------- " << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "r[" << i << "]";
        if (r[i].isGem(2) == 1)
        {
            cout << "have type 2" << endl;
        }
        else
        {
            cout << "don't have type 2 " << endl;
        }
    }

    cout << "\n-----destruct-----" << endl;
}