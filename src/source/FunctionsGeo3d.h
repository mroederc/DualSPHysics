//HEAD_DSCODES
/*
 <DUALSPHYSICS>  Copyright (c) 2019 by Dr Jose M. Dominguez et al. (see http://dual.sphysics.org/index.php/developers/). 

 EPHYSLAB Environmental Physics Laboratory, Universidade de Vigo, Ourense, Spain.
 School of Mechanical, Aerospace and Civil Engineering, University of Manchester, Manchester, U.K.

 This file is part of DualSPHysics. 

 DualSPHysics is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License 
 as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 
 DualSPHysics is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details. 

 You should have received a copy of the GNU Lesser General Public License along with DualSPHysics. If not, see <http://www.gnu.org/licenses/>. 
*/

//:#############################################################################
//:# Descripcion:
//:# =============
//:# Conjunto de funciones tipicas de geometria 3D.
//:#
//:# Cambios:
//:# =========
//:# - Implementacion a partir de FunctionsMath. (08-02-2019)
//:# - Cambio de nombres:
//:#     PointPlane() ----------> PlanePoint()
//:#     DistPlaneSign() -------> PlaneDistSign()
//:#     DistPlane() -----------> PlaneDist()
//:#     DistPoints() ----------> PointsDist()
//:#     DistPoint() -----------> PointDist()
//:#     VecUnitary() ----------> none
//:#     VecUnitarySafe() ------> VecUnitary()
//:#     CorrectNormal() -------> NormalCorrect()
//:#     NormalTriangle() ------> TriangleNormal()
//:#     PtOrthogonal() --------> PlaneOrthogonalPoint()
//:#     NormalPlanes3Pt() -----> TriangleNormalPlanes()
//:#     NormalPlanes3Pt_dbl() -> TriangleNormalPlanes_dbl()
//:#     Intersec3Planes() -----> PlanesIntersec()
//:#     IntersecPlaneLine() ---> PlaneLineIntersec()  
//:#     OpenTriangle3Pt() -----> TriangleOpen()
//:#     AreaTriangle() --------> TriangleArea()
//:#     DistLine() ------------> LinePointDist()
//:#     AngleVector() ---------> VectorsAngle()
//:#     AnglePlanes() ---------> PlanesAngle()
//:#     struct StRect3d -------> struct tline3d
//:#     Rect3d2pt() -----------> TLine3d2Pt()
//:#     RectPosX() ------------> LinePointX()
//:#     RectPosY() ------------> LinePointY()
//:#     RectPosZ() ------------> LinePointZ()
//:# - Nuevas funciones TriangleInside(), PolygonNormalPlanes(), PolygonInside(). (08-02-2019)
//:# - Nuevas funciones LineOrthogonalPoint(), LineOrthogonalPointFromPr1(). (29-05-2019)
//:# - Nuevas funciones LineNearestPoint(). (04-06-2019)
//:#############################################################################

/// \file FunctionsGeo3d.h \brief Declares geometry functions for 3D.

#ifndef _FunctionsGeo3d_
#define _FunctionsGeo3d_

#include "TypesDef.h"
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <vector>

/// Implements a set of basic/general math functions.
namespace fgeo{

double TriangleArea(const tdouble3 &p1,const tdouble3 &p2,const tdouble3 &p3);
float TriangleArea(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3);


//==============================================================================
/// Devuelve el producto escalar de 2 vectores.
/// Returns the scalar product of two vectors.
//==============================================================================
inline double ProductScalar(tdouble3 v1,tdouble3 v2){
  return(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

//==============================================================================
/// Devuelve el producto escalar de 2 vectores.
/// Returns the scalar product of two vectors.
//==============================================================================
inline float ProductScalar(tfloat3 v1,tfloat3 v2){
  return(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}


//==============================================================================
/// Devuelve el producto vectorial de 2 vectores.
/// Returns the vectorial product of two vectors.
//==============================================================================
inline tdouble3 ProductVec(const tdouble3 &v1,const tdouble3 &v2){
  tdouble3 r;
  r.x=v1.y*v2.z - v1.z*v2.y;
  r.y=v1.z*v2.x - v1.x*v2.z;
  r.z=v1.x*v2.y - v1.y*v2.x;
  return(r);
}

//==============================================================================
/// Devuelve el producto vectorial de 2 vectores.
/// Returns the vectorial product of two vectors.
//==============================================================================
inline tfloat3 ProductVec(const tfloat3 &v1,const tfloat3 &v2){
  tfloat3 r;
  r.x=v1.y*v2.z - v1.z*v2.y;
  r.y=v1.z*v2.x - v1.x*v2.z;
  r.z=v1.x*v2.y - v1.y*v2.x;
  return(r);
}


//==============================================================================
/// Devuelve la distancia entre dos puntos.
/// Returns the distance between two points.
//==============================================================================
inline double PointsDist(const tdouble3 &p1,const tdouble3 &p2){
  const tdouble3 v=p1-p2;
  return(sqrt(v.x*v.x+v.y*v.y+v.z*v.z));
}

//==============================================================================
/// Devuelve la distancia entre dos puntos.
/// Returns the distance between two points.
//==============================================================================
inline float PointsDist(const tfloat3 &p1,const tfloat3 &p2){
  const tfloat3 v=p1-p2;
  return(sqrt(v.x*v.x+v.y*v.y+v.z*v.z));
}


//==============================================================================
/// Devuelve la distancia al (0,0,0).
/// Returns the distance from (0,0,0).
//==============================================================================
inline double PointDist(const tdouble3 &p1){
  return(sqrt(p1.x*p1.x+p1.y*p1.y+p1.z*p1.z));
}

//==============================================================================
/// Devuelve la distancia al (0,0,0).
/// Returns the distance from (0,0,0).
//==============================================================================
inline float PointDist(const tfloat3 &p1){
  return(sqrt(p1.x*p1.x+p1.y*p1.y+p1.z*p1.z));
}


//==============================================================================
/// Devuelve vector unitario valido del vector or (0,0,0).
/// Returns a valid unit vector of the vector or (0,0,0).
//==============================================================================
inline tdouble3 VecUnitary(const tdouble3 &v){
  const double m=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
  return(m? TDouble3(v.x/m,v.y/m,v.z/m): v);
}

//==============================================================================
/// Devuelve vector unitario valido del vector or (0,0,0).
/// Returns a valid unit vector of the vector or (0,0,0).
//==============================================================================
inline tfloat3 VecUnitary(const tfloat3 &v){
  const float m=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
  return(m? TFloat3(v.x/m,v.y/m,v.z/m): v);
}


//==============================================================================
/// Devuelve vector unitario valido del vector or (0,0,0).
/// Returns a valid unit vector of the vector or (0,0,0).
//==============================================================================
inline tdouble3 VecModule(const tdouble3 &v,double module){
  const double m=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
  const double m2=(m? module/m: 0);
  return(m? TDouble3(v.x*m2,v.y*m2,v.z*m2): v);
}

//==============================================================================
/// Devuelve vector unitario valido del vector or (0,0,0).
/// Returns a valid unit vector of the vector or (0,0,0).
//==============================================================================
inline tfloat3 VecModule(const tfloat3 &v,float module){
  const float m=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
  const float m2=(m? module/m: 0);
  return(m? TFloat3(v.x*m2,v.y*m2,v.z*m2): v);
}


//==============================================================================
/// Devuelve punto eliminando error de precision en double.
/// Returns point removing the error of precision in double.
//==============================================================================
inline tdouble3 PointCorrect(const tdouble3 &v,int m=10){
  return(TDouble3((fabs(v.x)<DBL_EPSILON*m? 0: v.x)
                 ,(fabs(v.y)<DBL_EPSILON*m? 0: v.y)
                 ,(fabs(v.z)<DBL_EPSILON*m? 0: v.z)));
}

//==============================================================================
/// Devuelve punto eliminando error de precision en double.
/// Returns point removing the error of precision in double.
//==============================================================================
inline tfloat3 PointCorrect(const tfloat3 &v,int m=10){
  return(TFloat3((fabs(v.x)<FLT_EPSILON*m? 0: v.x)
                ,(fabs(v.y)<FLT_EPSILON*m? 0: v.y)
                ,(fabs(v.z)<FLT_EPSILON*m? 0: v.z)));
}


//==============================================================================
/// Devuelve normal eliminando error de precision en double.
/// Returns normal removing the error of precision in double.
//==============================================================================
inline tdouble3 NormalCorrect(tdouble3 n,int m=10){
  return(VecUnitary(PointCorrect(n,m)));
}

//==============================================================================
/// Devuelve normal eliminando error de precision en float.
/// Returns normal removing the error of precision in float.
//==============================================================================
inline tfloat3 NormalCorrect(tfloat3 n,int m=10){
  return(VecUnitary(PointCorrect(n,m)));
}


//==============================================================================
// Devuelve un vector ortogonal al dado con el modulo indicado.
// Returns an orthogonal vector with indicated module.
//==============================================================================
inline tdouble3 VecOrthogonal2(const tdouble3 &v,double module,bool first=true){
  tdouble3 r=TDouble3(0);
  if(v.x)r=(first? TDouble3(-v.z,0,v.x): TDouble3(-v.y,v.x,0));       //-When a!=0 in (a,b,c) => (-b,a,0)*y+(-c,0,a)*z 
  else if(v.y)r=(first? TDouble3(0,-v.z,v.y): TDouble3(v.y,-v.x,0));  //-When b!=0 in (a,b,c) => (0,-c,b)*z+(b,-a,0)*x 
  else if(v.z)r=(first? TDouble3(v.z,0,-v.x): TDouble3(0,v.z,-v.y));  //-When z!=0 in (a,b,c) => (c,0,-a)*x+(0,c,-b)*y 
  return(VecModule(r,module));
}

//==============================================================================
// Devuelve un vector ortogonal al dado con el modulo indicado.
// Returns an orthogonal vector with indicated module.
//==============================================================================
inline tfloat3 VecOrthogonal2(const tfloat3 &v,float module,bool first=true){
  tfloat3 r=TFloat3(0);
  if(v.x)r=(first? TFloat3(-v.z,0,v.x): TFloat3(-v.y,v.x,0));       //-When a!=0 in (a,b,c) => (-b,a,0)*y+(-c,0,a)*z 
  else if(v.y)r=(first? TFloat3(0,-v.z,v.y): TFloat3(v.y,-v.x,0));  //-When b!=0 in (a,b,c) => (0,-c,b)*z+(b,-a,0)*x 
  else if(v.z)r=(first? TFloat3(v.z,0,-v.x): TFloat3(0,v.z,-v.y));  //-When z!=0 in (a,b,c) => (c,0,-a)*x+(0,c,-b)*y 
  return(VecModule(r,module));
}

//==============================================================================
// Devuelve un vector ortogonal al dado con el modulo indicado.
// Returns an orthogonal vector with indicated module.
//==============================================================================
inline tdouble3 VecOrthogonal(const tdouble3 &v,double module){
  tdouble3 r=TDouble3(0);
  if(v.x)r=TDouble3((-v.y-v.z)/v.x,1,1);
  else if(v.y)r=TDouble3(1,(-v.x-v.z)/v.y,1);
  else if(v.z)r=TDouble3(1,1,(-v.x-v.y)/v.z);
  return(VecModule(r,module));
}

//==============================================================================
// Devuelve un vector ortogonal al dado con el modulo indicado.
// Returns an orthogonal vector with indicated module.
//==============================================================================
inline tfloat3 VecOrthogonal(const tfloat3 &v,float module){
  tfloat3 r=TFloat3(0);
  if(v.x)r=TFloat3((-v.y-v.z)/v.x,1,1);
  else if(v.y)r=TFloat3(1,(-v.x-v.z)/v.y,1);
  else if(v.z)r=TFloat3(1,1,(-v.x-v.y)/v.z);
  return(VecModule(r,module));
}

//==============================================================================
/// Devuelve el angulo en grados que forman dos vectores.
/// Returns angle in degrees between two vectors.
//==============================================================================
inline double VectorsAngle(const tdouble3 &v1,const tdouble3 &v2){
  return(acos(ProductScalar(v1,v2)/(PointDist(v1)*PointDist(v2)))*TODEG);
}

//==============================================================================
/// Devuelve el angulo en grados que forman dos vectores.
/// Returns angle in degrees between two vectors.
//==============================================================================
inline float VectorsAngle(const tfloat3 &v1,const tfloat3 &v2){
  return(float(acos(ProductScalar(v1,v2)/(PointDist(v1)*PointDist(v2)))*TODEG));
}


//==============================================================================
/// Devuelve recta definida por 2 puntos.
/// Returns rect defined by 2 points.
//==============================================================================
inline tline3d TLine3d2Pt(tdouble3 p1,tdouble3 p2){
  tline3d r={p1,VecUnitary(p2-p1)};
  return(r);
}

//==============================================================================
/// Devuelve recta definida por un puntos y un vector.
/// Returns rect defined by one point and one vector.
//==============================================================================
inline tline3d TLine3dPtVec(tdouble3 pt,tdouble3 vec){
  tline3d r={pt,VecUnitary(vec)};
  return(r);
}


//==============================================================================
/// Devuelve posicion en la recta para un valor de X o DBL_MAX para posiciones no validas.
/// Returns position on the rect for a X value or DBL_MAX for invalid positions.
//==============================================================================
inline tdouble3 LinePointX(const tline3d &r,double x){
  if(r.v.x==0)return(TDouble3(DBL_MAX));
  const double f=(x-r.p.x)/r.v.x;
  return(TDouble3(x,r.p.y+f*r.v.y,r.p.z+f*r.v.z));
}

//==============================================================================
/// Devuelve posicion en la recta para un valor de Y o DBL_MAX para posiciones no validas.
/// Returns position on the rect for a Y value or DBL_MAX for invalid positions.
//==============================================================================
inline tdouble3 LinePointY(const tline3d &r,double y){
  if(r.v.y==0)return(TDouble3(DBL_MAX));
  const double f=(y-r.p.y)/r.v.y;
  return(TDouble3(r.p.x+f*r.v.x,y,r.p.z+f*r.v.z));
}

//==============================================================================
/// Devuelve posicion en la recta para un valor de Z o DBL_MAX para posiciones no validas.
/// Returns position on the rect for a Z value or DBL_MAX for invalid positions.
//==============================================================================
inline tdouble3 LinePointZ(const tline3d &r,double z){
  if(r.v.z==0)return(TDouble3(DBL_MAX));
  const double f=(z-r.p.z)/r.v.z;
  return(TDouble3(r.p.x+f*r.v.x,r.p.y+f*r.v.y,z));
}


//==============================================================================
/// Devuelve la distancia entre un punto y una recta entre dos puntos.
/// Returns the distance between a point and a line between two points.
//==============================================================================
inline double LinePointDist(const tdouble3 &pt,const tdouble3 &pr1,const tdouble3 &pr2){
  double ar=TriangleArea(pt,pr1,pr2);
  double dis=PointsDist(pr1,pr2);
  return((ar*2)/dis);
}

//==============================================================================
/// Devuelve la distancia entre un punto y una recta entre dos puntos.
/// Returns the distance between a point and a line between two points.
//==============================================================================
inline float LinePointDist(const tfloat3 &pt,const tfloat3 &pr1,const tfloat3 &pr2){
  float ar=TriangleArea(pt,pr1,pr2);
  float dis=PointsDist(pr1,pr2);
  return((ar*2)/dis);
}


//==============================================================================
/// Devuelve proyeccion ortogonal del punto en la linea (pr1,pr2).
/// Returns orthogonal projection of the point in the line (pr1,pr2).
//==============================================================================
inline tdouble3 LineOrthogonalPoint(const tdouble3 &pt,const tdouble3 &pr1,const tdouble3 &pr2);

//==============================================================================
/// Devuelve proyeccion ortogonal del punto en la linea (pr1,pr2).
/// Returns orthogonal projection of the point in the line (pr1,pr2).
//==============================================================================
inline tfloat3 LineOrthogonalPoint(const tfloat3 &pt,const tfloat3 &pr1,const tfloat3 &pr2);


//==============================================================================
/// Devuelve proyeccion ortogonal del punto en la linea (pr1,pr2). Devuelve 0.0 
/// cuando la proyeccion coincide con pr1, 0.5 en la mitad del segmeneto y 1.0 
/// en el punto pr2.
/// Returns orthogonal projection of the point in the line (pr1,pr2).
//==============================================================================
double LineOrthogonalPointFromPr1(const tdouble3 &pt,const tdouble3 &pr1,const tdouble3 &pr2);

//==============================================================================
/// Devuelve proyeccion ortogonal del punto en la linea (pr1,pr2). Devuelve 0.0 
/// cuando la proyeccion coincide con pr1, 0.5 en la mitad del segmeneto y 1.0 
/// en el punto pr2.
/// Returns orthogonal projection of the point in the line (pr1,pr2).
//==============================================================================
float LineOrthogonalPointFromPr1(const tfloat3 &pt,const tfloat3 &pr1,const tfloat3 &pr2);


//==============================================================================
/// Devuelve punto del segmento (pr1,pr2) mas cercano al punto pt.
/// Returns point in segment (pr1,pr2) closest to point pt.
//==============================================================================
inline tdouble3 LineNearestPoint(const tdouble3 &pt,const tdouble3 &pr1,const tdouble3 &pr2){
  const double t=LineOrthogonalPointFromPr1(pt,pr1,pr2);
  if(t<=0)return(pr1);
  if(t>=1.0)return(pr2);
  return(pr1+((pr2-pr1)*t));
}

//==============================================================================
/// Devuelve punto del segmento (pr1,pr2) mas cercano al punto pt.
/// Returns point in segment (pr1,pr2) closest to point pt.
//==============================================================================
inline tfloat3 LineNearestPoint(const tfloat3 &pt,const tfloat3 &pr1,const tfloat3 &pr2){
  const float t=LineOrthogonalPointFromPr1(pt,pr1,pr2);
  if(t<=0)return(pr1);
  if(t>=1.0)return(pr2);
  return(pr1+((pr2-pr1)*t));
}

//==============================================================================
/// Devuelve el plano formado por 3 puntos.
/// Returns the plane defined by 3 points.
//==============================================================================
tplane3d Plane3Pt(const tdouble3 &p1,const tdouble3 &p2,const tdouble3 &p3);

//==============================================================================
/// Devuelve el plano formado por 3 puntos.
/// Returns the plane defined by 3 points.
//==============================================================================
tplane3f Plane3Pt(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3);


//==============================================================================
/// Devuelve el plano formado por un punto y un vector.
/// Returns the plane defined by a point and a vector.
//==============================================================================
inline tplane3d PlanePtVec(const tdouble3 &pt,const tdouble3 &vec){
  const tdouble3 v=VecUnitary(vec);//-No es necesario pero asi el modulo del vector no afecta al resultado de PointPlane().
  return(TPlane3d(v.x,v.y,v.z,-v.x*pt.x-v.y*pt.y-v.z*pt.z));
}

//==============================================================================
/// Devuelve el plano formado por un punto y un vector.
/// Returns the plane defined by a point and a vector.
//==============================================================================
inline tplane3f PlanePtVec(const tfloat3 &pt,const tfloat3 &vec){
  const tfloat3 v=VecUnitary(vec);//-No es necesario pero asi el modulo del vector no afecta al resultado de PointPlane().
  return(TPlane3f(v.x,v.y,v.z,-v.x*pt.x-v.y*pt.y-v.z*pt.z));
}


//==============================================================================
/// Resuelve punto en el plano.
/// Solves point in the plane.
//==============================================================================
inline double PlanePoint(const tplane3d &pla,const tdouble3 &pt){ 
  return(pla.a*pt.x+pla.b*pt.y+pla.c*pt.z+pla.d);
}

//==============================================================================
/// Resuelve punto en el plano.
/// Solves point in the plane.
//==============================================================================
inline float PlanePoint(const tplane3f &pla,const tfloat3 &pt){ 
  return(pla.a*pt.x+pla.b*pt.y+pla.c*pt.z+pla.d);
}


//==============================================================================
/// Devuelve la distancia entre un punto y un plano con signo.
/// Returns the distance between a point and a plane with sign.
//==============================================================================
inline double PlaneDistSign(const tplane3d &pla,const tdouble3 &pt){
  return(PlanePoint(pla,pt)/sqrt(pla.a*pla.a+pla.b*pla.b+pla.c*pla.c));
}

//==============================================================================
/// Devuelve la distancia entre un punto y un plano con signo.
/// Returns the distance between a point and a plane with sign.
//==============================================================================
inline float PlaneDistSign(const tplane3f &pla,const tfloat3 &pt){ 
  return(PlanePoint(pla,pt)/sqrt(pla.a*pla.a+pla.b*pla.b+pla.c*pla.c));
}


//==============================================================================
/// Devuelve la distancia entre un punto y un plano.
/// Returns the distance between a point and a plane.
//==============================================================================
inline double PlaneDist(const tplane3d &pla,const tdouble3 &pt){ 
  return(fabs(PlaneDistSign(pla,pt)));
}

//==============================================================================
/// Devuelve la distancia entre un punto y un plano.
/// Returns the distance between a point and a plane.
//==============================================================================
inline float PlaneDist(const tplane3f &pla,const tfloat3 &pt){ 
  return(fabs(PlaneDistSign(pla,pt)));
}


//==============================================================================
/// Devuelve el angulo en grados que forman dos planos.
/// Returns angle in degrees between two planes.
//==============================================================================
inline double PlanesAngle(tplane3d v1,tplane3d v2){
  return(VectorsAngle(TDouble3(v1.a,v1.b,v1.c),TDouble3(v2.a,v2.b,v2.c)));
}

//==============================================================================
/// Devuelve el angulo en grados que forman dos planos.
/// Returns angle in degrees between two planes.
//==============================================================================
inline float PlanesAngle(tplane3f v1,tplane3f v2){
  return(VectorsAngle(TFloat3(v1.a,v1.b,v1.c),TFloat3(v2.a,v2.b,v2.c)));
}


//==============================================================================
/// Devuelve proyeccion ortogonal del punto en el plano.
/// Returns orthogonal projection of the point in the plane.
//==============================================================================
inline tdouble3 PlaneOrthogonalPoint(const tdouble3 &pt,const tplane3d &pla){
  const double t=-(pla.a*pt.x+pla.b*pt.y+pla.c*pt.z+pla.d)/(pla.a*pla.a+pla.b*pla.b+pla.c*pla.c);
  return(TDouble3(pt.x+pla.a*t,pt.y+pla.b*t,pt.z+pla.c*t));
}

//==============================================================================
/// Devuelve proyeccion ortogonal del punto en el plano.
/// Returns orthogonal projection of the point in the plane.
//==============================================================================
inline tfloat3 PlaneOrthogonalPoint(const tfloat3 &pt,const tplane3f &pla){
  const float t=-(pla.a*pt.x+pla.b*pt.y+pla.c*pt.z+pla.d)/(pla.a*pla.a+pla.b*pla.b+pla.c*pla.c);
  return(TFloat3(pt.x+pla.a*t,pt.y+pla.b*t,pt.z+pla.c*t));
}


//==============================================================================
/// Devuelve punto de interseccion entre 3 planos no paralelos entre si.
/// Returns intersection of three planes not parallel to each other.
//==============================================================================
tdouble3 PlanesIntersec(const tplane3d &pla1,const tplane3d &pla2,const tplane3d &pla3);

//==============================================================================
/// Devuelve punto de interseccion entre 3 planos no paralelos entre si.
/// Returns intersection of three planes not parallel to each other.
//==============================================================================
tfloat3 PlanesIntersec(const tplane3f &pla1,const tplane3f &pla2,const tplane3f &pla3);


//==============================================================================
/// Devuelve punto de interseccion entre un plano y una linea.
/// Returns intersection of a plane and a line.
//==============================================================================
tdouble3 PlaneLineIntersec(const tplane3d &pla,const tdouble3 &pt1,const tdouble3 &pt2);

//==============================================================================
/// Devuelve punto de interseccion entre un plano y una linea.
/// Returns intersection of a plane and a line.
//==============================================================================
tfloat3 PlaneLineIntersec(const tplane3f &pla,const tfloat3 &pt1,const tfloat3 &pt2);


//==============================================================================
/// Devuelve el area de un triangulo formado por 3 puntos.
/// Returns the area of a triangle formed by 3 points.
//==============================================================================
double TriangleArea(const tdouble3 &p1,const tdouble3 &p2,const tdouble3 &p3);

//==============================================================================
/// Devuelve el area de un triangulo formado por 3 puntos.
/// Returns the area of a triangle formed by 3 points.
//==============================================================================
float TriangleArea(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3);


//==============================================================================
/// Devuelve la normal de un triangulo.
/// Returns the normal of a triangle.
//==============================================================================
inline tdouble3 TriangleNormal(const tdouble3& p1,const tdouble3& p2,const tdouble3& p3){
  return(ProductVec(p1-p2,p2-p3));
}

//==============================================================================
/// Devuelve la normal de un triangulo.
/// Returns the normal of a triangle.
//==============================================================================
inline tfloat3 TriangleNormal(const tfloat3& p1,const tfloat3& p2,const tfloat3& p3){
  return(ProductVec(p1-p2,p2-p3));
}


//==============================================================================
/// Devuelve los tres planos normales que limitan un triangulo formado por 3 puntos.
/// Con openingdist puedes abrir o cerrar los planos normales.
/// Returns the three normal planes which bound a triangle formed by 3 points.
/// With openingdist you can open or close normal planes.
//==============================================================================
void TriangleNormalPlanes(const tdouble3 &p1,const tdouble3 &p2,const tdouble3 &p3
  ,double openingdist,tplane3d &pla1,tplane3d &pla2,tplane3d &pla3);

//==============================================================================
/// Devuelve los tres planos normales que limitan un triangulo formado por 3 puntos.
/// Con openingdist puedes abrir o cerrar los planos normales.
/// Returns the three normal planes which bound a triangle formed by 3 points.
/// With openingdist you can open or close normal planes.
//==============================================================================
void TriangleNormalPlanes(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3
  ,float openingdist,tplane3f &pla1,tplane3f &pla2,tplane3f &pla3);

//==============================================================================
/// Devuelve los tres planos normales que limitan un triangulo formado por 3 puntos.
/// Con openingdist puedes abrir o cerrar los planos normales.
/// Los calculos internos se hacen con double precision.
/// Returns the three normal planes which bound a triangle formed by 3 points.
/// With openingdist you can open or close normal levels.
/// The internal computation is performed with double precision.
//==============================================================================
inline void TriangleNormalPlanes_dbl(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3
  ,float openingdist,tplane3f &pla1,tplane3f &pla2,tplane3f &pla3)
{
  tplane3d plad1,plad2,plad3;
  TriangleNormalPlanes(ToTDouble3(p1),ToTDouble3(p2),ToTDouble3(p3),double(openingdist),plad1,plad2,plad3);
  pla1=TPlane3f(plad1); pla2=TPlane3f(plad2); pla3=TPlane3f(plad3);
}


//==============================================================================
/// Devuelve true cuando el punto esta dentro de 3 planos.
/// Returns true when the point is inside 3 planes.
//==============================================================================
bool TriangleInside(const tdouble3 &pt,const tplane3d &pla1,const tplane3d &pla2,const tplane3d &pla3);

//==============================================================================
/// Devuelve true cuando el punto esta dentro de 3 planos.
/// Returns true when the point is inside 3 planes.
//==============================================================================
bool TriangleInside(const tfloat3 &pt,const tplane3f &pla1,const tplane3f &pla2,const tplane3f &pla3);


//==============================================================================
/// A partir de un triangulo formado por 3 puntos devuelve los puntos que forman
/// un triangulo mas o menos abierto segun openingdist.
/// Starting from a triangle formed by 3 points returns the points that form
/// a triangle more or less open according to openingdist.
//==============================================================================
void TriangleOpen(const tdouble3 &p1,const tdouble3 &p2,const tdouble3 &p3
  ,double openingdist,tdouble3 &pt1,tdouble3 &pt2,tdouble3 &pt3);

//==============================================================================
/// A partir de un triangulo formado por 3 puntos devuelve los puntos que forman
/// un triangulo mas o menos abierto segun openingdist.
/// Starting from a triangle formed by 3 points returns the points that form
/// a triangle more or less open according to openingdist.
//==============================================================================
void TriangleOpen(const tfloat3 &p1,const tfloat3 &p2,const tfloat3 &p3
  ,float openingdist,tfloat3 &pt1,tfloat3 &pt2,tfloat3 &pt3);


//==============================================================================
/// Devuelve los planos normales que limitan un poligono convexo formado por np puntos.
/// Con openingdist puedes abrir o cerrar los planos normales.
/// Returns the normal planes which bound a convex polygon formed by np points.
/// With openingdist you can open or close normal planes.
//==============================================================================
void PolygonNormalPlanes(const std::vector<tdouble3> &vpt,double openingdist,std::vector<tplane3d> &vpla);

//==============================================================================
/// Devuelve los planos normales que limitan un poligono convexo formado por np puntos.
/// Con openingdist puedes abrir o cerrar los planos normales.
/// Returns the normal planes which bound a convex polygon formed by np points.
/// With openingdist you can open or close normal planes.
//==============================================================================
void PolygonNormalPlanes(const std::vector<tfloat3> &vpt,float openingdist,std::vector<tplane3f> &vpla);


//==============================================================================
/// Devuelve true cuando el punto esta dentro de los planos.
/// Returns true when the point is inside planes.
//==============================================================================
bool PolygonInside(const tdouble3 &pt,const std::vector<tplane3d> &vpla);

//==============================================================================
/// Devuelve true cuando el punto esta dentro de los planos.
/// Returns true when the point is inside planes.
//==============================================================================
bool PolygonInside(const tfloat3 &pt,const std::vector<tplane3f> &vpla);


//==============================================================================
/// Devuelve true cuando el punto esta dentro de los planos.
/// Returns true when the point is inside planes.
bool PolygonInside(const tdouble3 &pt,unsigned npla,const tplane3d *vpla);

  //==============================================================================
/// Devuelve true cuando el punto esta dentro de los planos.
/// Returns true when the point is inside planes.
bool PolygonInside(const tfloat3 &pt,unsigned npla,const tplane3f *vpla);

}

#endif


