#include <iostream>
using namespace std;

class Gem
{
private:
    int type;         // 1: เพชร, 2: ทับทิม, 3: หยก, 4: ไพลิน, 5: มุก
    static int count; // นับจำนวนออบเจ็กต์

public:
    // Default constructor
    Gem()
    {
        setType(5);
        count++;
    }

    // Constructor กำหนดค่าเริ่มต้น
    Gem(int t)
    {
        setType(5);
        count++;
    }

    // Destructor
    ~Gem()
    {
        count--;
        cout << "Delete Gem: " << "Type " << type << endl;
    }

    // Setter
    void setType(int t)
    {
        if (t >= 1 && t <= 5)
        {
            type = t;
        }
    }

    // Getter
    int getType() { return type; }

    // Show function
    void showGem()
    {
        cout << "Show Gem: "
                "Type "
             << type << endl;
    }

    /*string showType(){
        switch (type) {
            case 1: return "เพชร";
            case 2: return "ทับทิม";
            case 3: return "หยก";
            case 4: return "ไพลิน";
            case 5: return "มุก";
            default: return "ไม่มีชนิดนี้ขาย";
        }
    }*/

    // ฟังก์ชันนับจำนวนออบเจ็กต์
    static int getCount() { return count; }
};

int Gem::count; // กำหนดค่าเริ่มต้นให้ count

class Jewelry
{
private:
    double price;
    int madeFrom; // 1: ทอง, 2: เงิน, 3: ทองคำขาว

public:
    // Default constructor
    Jewelry() { setJewelry(990, 2); }

    // Constructor กำหนดค่าเริ่มต้น
    Jewelry(double p, int m) { setJewelry(p, m); }

    // Destructor
    ~Jewelry() { cout << "Delete Jewelry: " << " Made From:" << madeFrom << " Price:" << price << endl; }

    // Setter
    void setJewelry(double p, int m)
    {
        if (p > 0)
        {
            price = p;
        }
        if (m >= 1 && m <= 3)
        {
            madeFrom = m;
        }
    }
    void setPrice(double p)
    {
        if (p > 0)
            price = p;
    }
    void setMadeFrom(int m)
    {
        if (m >= 1 && m <= 3)
            madeFrom = m;
    }

    // Getter
    double getPrice() { return price; }
    int getMadeFrom() { return madeFrom; }

    // Show function
    void showJewelry() { cout << "Price: " << price << " Made From: " << madeFrom << endl; }
    /*string showMadeFrom(){
        switch (madeFrom)
        {
        case 1:return " เงิน";
        case 2:return " ทอง";
        case 3:return" ทองคำขาว";
        default:return"ไม่มีชนิดนี้ขาย";
        }
    }*/
};

class Ring : public Jewelry
{
private:
    Gem **gems; // อาร์เรย์ของ pointer ที่ชี้ไปยัง Gem objects
    int num;    // ขนาดของอาร์เรย์ gems

public:
    // Default constructor
    Ring() : Jewelry(), gems(nullptr)
    {
        setJewelry(3000, 3);
        setNum(0);
    }

    // Constructor กำหนดค่าเริ่มต้น
    Ring(int n, double p, int m) : Jewelry(p, m), gems(nullptr)
    {
        setNum(n);
        gems = new Gem *[n];
    }

    // Destructor
    ~Ring()
    {
        if (gems != nullptr)
        {
            delete[] gems; // ลบอาร์เรย์ gems
        }
        cout << "Delete Ring " << num + 1 << " Made From:" << getMadeFrom() << " Price:" << getPrice() << endl;
    }

    // Setter
    void setNum(int n)
    {
        if (n >= 0)
        {
            num = n;
            gems = new Gem *[num];
        }
    }

    // Setter for a specific gem
    void setGems(int i, Gem *g)
    {
        if (i >= 0 && i < num)
        {
            gems[i] = g;
        }
    }

    // ฟังก์ชันตรวจสอบว่ามี Gem ชนิดที่กำหนดหรือไม่
    bool isGem(int type)
    {
        for (int i = 0; i < num; i++)
        {
            if (gems[i]->getType() == type)
            {
                return true;
            }
        }
        return false;
    }

    // Getter
    Gem *getGem(int i)
    {
        if (i >= 0 && i < num)
        {
            return gems[i];
        }
        return nullptr;
    }

    int getNum() { return num; }

    // Show function
    void showRing()
    {
        cout << "Show Ring: " << " Number of Gems: " << num << endl;
        showJewelry();
    }
};

class Necklace : public Jewelry
{
private:
    bool pendant; // มีจี้หรือไม่

public:
    Necklace() : Jewelry()
    {
        setJewelry(22000, 1);
        setPendant(true);
    }
    Necklace(double p, int m, bool pd) : Jewelry(p, m) { setPendant(pd); }
    ~Necklace() { cout << "\nDelete Necklace " << " Made From:" << getMadeFrom() << " Price:" << getPrice() << " Pendant: " << pendant << endl; }

    void setPendant(bool pd) { pendant = pd; }
    bool getPendant() { return pendant; }

    void showNecklace()
    {
        cout << "\nShow Necklace " << " Pendant: " << pendant << endl;
        showJewelry();
    }
};

int main()
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

    // แสดงรายละเอียดของ g
    cout << "Gem details:" << endl;
    for (int i = 0; i < 8; i++)
    {
        g[i].showGem();
    }

    // สร้างอาร์เรย์ของ Ring ขนาด 2
    Ring r[2];
    r[0].setNum(1);         // กำหนดจำนวนอัญมณีใน r[0]
    r[0].setGems(0, &g[5]); // ประดับไข่มุก g[5]
    r[0].setPrice(33000);
    r[0].setMadeFrom(2); // เงิน

    r[1].setNum(3);         // กำหนดจำนวนอัญมณีใน r[1]
    r[1].setGems(0, &g[2]); // ทับทิม g[2]
    r[1].setGems(1, &g[0]); // เพชร g[0]
    r[1].setGems(2, &g[1]); // เพชร g[1]
    r[1].setPrice(150000);
    r[1].setMadeFrom(1); // ทอง

    // แสดงรายละเอียดของ r
    cout << "\nRing details:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        r[i].showRing();
    }

    // สร้างอาร์เรย์ของ Necklace ขนาด 2
    Necklace n[2];
    n[0].setPrice(10000);
    n[0].setMadeFrom(3);   // ทองคำขาว
    n[0].setPendant(true); // มีจี้

    n[1].setPrice(20000);
    n[1].setMadeFrom(1);    // ทอง
    n[1].setPendant(false); // ไม่มีจี้

    // แสดงรายละเอียดของ n
    cout << "\nNecklace details:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << "Show Necklace: " << " Pendant: " << n[i].getPendant() << endl;
        cout << "Price: " << n[i].getPrice() << " Made From: ";
        switch (r[i].getMadeFrom())
        {
        case 1:
            cout << "ทอง";
            break;
        case 2:
            cout << "เงิน";
            break;
        case 3:
            cout << "ทองคำขาว";
            break;
        }
        cout << endl;
    }

    // แสดงผลรวมของราคาเครื่องประดับทั้งหมด
    double totalPrice = 0;
    for (int i = 0; i < 2; ++i)
    {
        totalPrice += r[i].getPrice();
    }
    for (int i = 0; i < 2; ++i)
    {
        totalPrice += n[i].getPrice();
    }
    cout << "\nTotal price of all jewelry: " << totalPrice << endl;

    // ตรวจสอบจำนวนเครื่องประดับที่เป็นทอง
    int goldCount = 0;
    if (r[0].getMadeFrom() == 1)
        goldCount++;
    if (r[1].getMadeFrom() == 1)
        goldCount++;
    if (n[0].getMadeFrom() == 1)
        goldCount++;
    if (n[1].getMadeFrom() == 1)
        goldCount++;
    cout << "Number of gold jewelry: " << goldCount << endl;

    // เปลี่ยนข้อมูลใน r[0]
    r[0].setNum(3);         // กำหนดจำนวนอัญมณีใหม่
    r[0].setGems(0, &g[4]); // ไพลิน g[4]
    r[0].setGems(1, &g[6]); // เพชร g[6]
    r[0].setGems(2, &g[7]); // เพชร g[7]
    r[0].setPrice(80000);

    // แสดงรายละเอียดของ r โดยเรียกใช้งาน get
    cout << "\nUpdated Ring details:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << "Ring " << i << ":" << endl;
        cout << "Price: " << r[i].getPrice() << endl;
        cout << "Made from: ";
        switch (r[i].getMadeFrom())
        {
        case 1:
            cout << "ทอง";
            break;
        case 2:
            cout << "เงิน";
            break;
        case 3:
            cout << "ทองคำขาว";
            break;
        }
        cout << endl;
    }

    for (int i = 0; i < r[i].getNum(); i++)
    {
        cout << "Number of gems: " << r[i].getNum() << endl;
        Gem *gem = r[i].getGem(i);
        if (gem)
            gem->showGem();
    }

    // ตรวจสอบว่าแหวนวงใดประดับทับทิม
    cout << "\nRings with ruby:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        if (r[i].isGem(2))
        { // ทับทิม
            cout << "Ring " << i << " has ruby." << endl;
            r[i].showRing();
        }
    }

    return 0;
}