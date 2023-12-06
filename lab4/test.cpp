#include <gtest/gtest.h>
#include "main.cpp"


TEST(Center, Rhombus)
{
    std::istringstream stream("0 0 0 1 1 1 1 0");

    Rhombus<double> figure;

    stream >> figure;

    Point<double> center(0.5, 0.5);

    ASSERT_TRUE(figure.Center() == center);
}

TEST(Center, Pentagon)
{
    std::istringstream stream("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951");

    Pentagon<double> figure;

    stream >> figure;

    Point<double> center(0, 0);

    ASSERT_TRUE(center == figure.Center());
}
TEST(Center, Hexagon)
{
    std::istringstream stream("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    Hexagon<double> figure;

    stream >> figure;

    Point<double> center(0, 0);

    ASSERT_TRUE(center == figure.Center());
}

TEST(Area, Rhombus)
{

    std::istringstream stream("0 0 0 1 1 1 1 0");

    Rhombus<double> figure;

    stream >> figure;

    double area = 4;

    ASSERT_TRUE(double(figure) - area < EPS);
}

TEST(Area, Pentagon)
{
    std::istringstream stream("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951" );

    Pentagon<double> figure;

    stream >> figure;

    double area = 2.376625;
    ASSERT_TRUE(double(figure) - area < EPS);
}

TEST(Area, Hexagon)
{

    std::istringstream stream("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    Hexagon<double> figure;

    stream >> figure;

    double area = 2.59807;

    ASSERT_TRUE(double(figure) - area < EPS);
}

TEST(Input, RhombusNoError)
{
    std::istringstream stream("0 0 1 0 1.70711 0.70711 0.70711 0.70711");

    Rhombus<double> figure;

    EXPECT_NO_THROW(stream >> figure);
}

TEST(Input, PentagonNoError)
{
    std::istringstream stream("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");

    Pentagon<double> figure;

    EXPECT_NO_THROW(stream >> figure);
}

TEST(Input, HexagonNoError)
{
    std::istringstream stream("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    Hexagon<double> figure;

    EXPECT_NO_THROW(stream >> figure);
}

TEST(Input, Rhombus)
{
    std::istringstream stream("0 0 1 0 1.70711 0.70711 0.70711 0.70711");

    Rhombus<double> figure;

    stream >> figure;

    PointArray<double> array(4);

    array.value[0] = Point<double>(0, 0);
    array.value[1] = Point<double>(1, 0);
    array.value[2] = Point<double>(1.70711, 0.70711);
    array.value[3] = Point<double>(0.70711, 0.70711);

    bool check = true;
    for (int i = 0; i < 4; i++) {
        if (!(array.value[i] == figure.points.value[i])) {
            check = false;
        }
    }

    EXPECT_TRUE(check);
}

TEST(Input, Pentagon)
{
    std::istringstream stream("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");

    Pentagon<double> figure;

    stream >> figure;

    PointArray<double>array(5);

    array.value[0] = Point<double>(0, 1);
    array.value[1] = Point<double>(0.951, 0.309);
    array.value[2] = Point<double>(0.588, -0.809);
    array.value[3] = Point<double>(-0.588, -0.809);
    array.value[4] = Point<double>(-0.951, -0.309);

    bool check = true;
    for (int i = 0; i < 5; i++) {
        if (!(array.value[i] == figure.points.value[i])) {
            check = false;
        }
    }

    EXPECT_TRUE(check);
}

TEST(Input, Hexagon)
{
    std::istringstream stream("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    Hexagon<double> figure;

    stream >> figure;

    PointArray<double>array(6);

    array.value[0] = Point<double>(1, 0);
    array.value[1] = Point<double>(0.5, 0.866);
    array.value[2] = Point<double>(-0.5, 0.866);
    array.value[3] = Point<double>(-1, 0);
    array.value[4] = Point<double>(-0.5, -0.866);
    array.value[5] = Point<double>(-0.5, -0.866);

    bool check = true;
    for (int i = 0; i < 6; i++) {
        if (!(array.value[i] == figure.points.value[i])) {
            check = false;
        }
    }

    EXPECT_TRUE(check);
}

TEST(Input, RhombusError)
{
    std::istringstream stream("0 0 1.5 0 3 1.5 1.5 1");

    Rhombus<double> figure;

    EXPECT_THROW(stream >> figure, std::invalid_argument);
}

TEST(Input, PentagonError)
{
    std::istringstream stream("0 0 1.5 0 3 1.5 1.5 1 5 5");

    Pentagon<double> figure;

    EXPECT_THROW(stream >> figure, std::invalid_argument);
}

TEST(Input, HexagonError)
{
    std::istringstream stream("0 0 1.5 0 3 1.5 1.5 1 7 9 5 1");

    Hexagon<double> figure;

    EXPECT_THROW(stream >> figure, std::invalid_argument);
}

TEST(Output, Rhombus)
{

    std::istringstream istream("0 0 0 1 1 1 1 0");
    std::ostringstream ostream;

    Rhombus<double> figure;

    istream >> figure;

    ostream << figure;

    std::string s = "0 0 0 1 1 1 1 0 ";
    ASSERT_TRUE(s == ostream.str());
}

TEST(Output, Pentagon)
{

    std::istringstream istream("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951");
    std::ostringstream ostream;

    Pentagon<double> figure;

    istream >> figure;

    ostream << figure;

    std::string s = "1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951 ";
    ASSERT_TRUE(s == ostream.str());
}

TEST(Output, Hexagon)
{

    std::istringstream istream("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");
    std::ostringstream ostream;

    Hexagon<double> figure;

    istream >> figure;

    ostream << figure;

    std::string s = "1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866 ";
    ASSERT_TRUE(s == ostream.str());
}

TEST(Comarison, Rhombus)
{

    Rhombus<double> figure1, figure2;

    std::istringstream stream1("0 0 1 0 1 1 0 1"), stream2("1 1 1.7071 0.2929 2.4142 1 1.7071 1.7071");

    stream1 >> figure1;
    stream2 >> figure2;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(Comarison, Pentagon)
{

    Pentagon<double> figure1, figure2;

    std::istringstream stream1("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951"), stream2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");

    stream1 >> figure1;
    stream2 >> figure2;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(Comarison, Hexagon)
{

    Hexagon<double> figure1, figure2;

    std::istringstream stream1("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866") , stream2("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    stream1 >> figure1;
    stream2 >> figure2;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(Copy, Rhombus)
{

    Rhombus<double> figure1, figure2;

    std::istringstream stream1("0 0 1 0 1 1 0 1");

    stream1 >> figure1;

    figure2 = figure1;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(Copy, Pentagon)
{

    Pentagon<double> figure1, figure2;

    std::istringstream stream1("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951");

    stream1 >> figure1;

    figure2 = figure1;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(Copy, Hexagon)
{

    Hexagon<double> figure1, figure2;

    std::istringstream stream1("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");

    stream1 >> figure1;

    figure2 = figure1;

    ASSERT_TRUE(figure1 == figure2);
}

TEST(FigureArray, AreaSum)
{

    Rhombus<double> figure1;
    Pentagon<double> figure2;
    Hexagon<double> figure3;

    std::istringstream stream1("0 0 1 0 1 1 0 1");
    std::istringstream stream2("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951");
    std::istringstream stream3("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");


    stream1 >> figure1;
    stream2 >> figure2;
    stream3 >> figure3;

    FigureArray<double> array(3);
    array.value[0] = figure1;
    array.value[1] = figure2;
    array.value[2] = figure3;
    
    double area = 1 + 2.37662 + 2.598;
    ASSERT_TRUE(abs(array.AreaSum() - area) < EPS);
}

TEST(FigureArray, Delete)
{

    Rhombus<double> figure1;
    Pentagon<double> figure2;
    Hexagon<double> figure3;

    std::istringstream stream1("0 0 1 0 1 1 0 1");
    std::istringstream stream2("1 0 0.309 0.951 -0.809 0.587 -0.809 -0.587 0.309 -0.951");
    std::istringstream stream3("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");


    stream1 >> figure1;
    stream2 >> figure2;
    stream3 >> figure3;

    FigureArray<double> array(3);
    array.value[0] = figure1;
    array.value[1] = figure2;
    array.value[2] = figure3;

    array.Delete(0);
    
    ASSERT_TRUE(array.value[0] == figure2);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
