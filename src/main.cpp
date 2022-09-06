#include "CalcGradient.hpp"
#include "FluidElement.hpp"
#include <array>
#include <iostream>

#include "ReadJson.hpp"


template<typename T>
void InitializeCells( T & cells)
{
    cells.at(0).position = 0;
    cells.at(0).velocity = 0;
    cells.at(0).pressure = 15;
    cells.at(0).density = 0.5;

    cells.at(1).position = 1;
    cells.at(1).velocity = 1;
    cells.at(1).pressure = 13;
    cells.at(1).density = 0.5;

    cells.at(2).position = 2;
    cells.at(2).velocity = 1;
    cells.at(2).pressure = 10;
    cells.at(2).density = 0.5;
}



int main()
{

    std::array<FluidElement, 3> cells;
    InitializeCells(cells);

    constexpr double timestep = 0.01;


    const auto viscosity = ReadDataEntryFromJson<double>("data.json", "Viscosity");



    const auto CellOfInterest_itr = cells.begin() + 1;
    auto &CellOfInterest = *CellOfInterest_itr; // = cells.at(1);

    const auto PositionFunction = [](auto &cell) { return cell.position; };
    const auto VelocityFunction = [](auto &cell) { return cell.velocity; };
    const auto PressureFunction = [](auto &cell) { return cell.pressure; };

    const auto VelocityGradient = CalcGradient(CellOfInterest_itr, PositionFunction, VelocityFunction);

    const auto VelocityLaplacian = CalcLaplacian(CellOfInterest_itr, PositionFunction, VelocityFunction);

    const auto PressureGradient = CalcGradient(CellOfInterest_itr, PositionFunction, PressureFunction);

    const auto PressureTerm = -PressureGradient / CellOfInterest.density;
    const auto ViscousTerm = viscosity * VelocityLaplacian;
    const auto InertiaTerm =  CellOfInterest.velocity * VelocityGradient;

    const auto VelocityTimeDerivative = PressureTerm + ViscousTerm - InertiaTerm;

    CellOfInterest.velocity += VelocityTimeDerivative * timestep;

    std::cout <<CellOfInterest.velocity;
}