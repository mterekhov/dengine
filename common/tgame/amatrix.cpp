#include "amatrix.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AMatrix AMatrix::rotationX(const TFloat angle)
{
	TFloat sine = sinf(angle);
	TFloat cosine = cosf(angle);
	
    AMatrix m;
	m.m[0][0] = 1.0;
	m.m[1][0] = 0.0;
	m.m[2][0] = 0.0;
	m.m[3][0] = 0.0;
	
	m.m[0][1] = 0.0;
	m.m[1][1] = (cosine);
	m.m[2][1] = (sine);
	m.m[3][1] = 0.0;
	
	m.m[0][2] = 0.0;
	m.m[1][2] = -(sine);
	m.m[2][2] = (cosine);
	m.m[3][2] = 0.0;
	
	m.m[0][3] = 0.0;
	m.m[1][3] = 0.0;
	m.m[2][3] = 0.0;
	m.m[3][3] = 1.0;
	
	return m;
}

//==============================================================================

AMatrix AMatrix::rotationY(const TFloat angle)
{
	TFloat sine = sinf(angle);
	TFloat cosine = cosf(angle);
	
    AMatrix m;
	m.m[0][0] = (cosine);
	m.m[1][0] = 0.0;
	m.m[2][0] = -(sine);
	m.m[3][0] = 0.0;
	
	m.m[0][1] = 0.0;
	m.m[1][1] = 1.0;
	m.m[2][1] = 0.0;
	m.m[3][1] = 0.0;
	
	m.m[0][2] = (sine);
	m.m[1][2] = 0.0;
	m.m[2][2] = (cosine);
	m.m[3][2] = 0.0;
	
	m.m[0][3] = 0.0;
	m.m[1][3] = 0.0;
	m.m[2][3] = 0.0;
	m.m[3][3] = 1.0;
	
	return m;
}

//==============================================================================

AMatrix AMatrix::rotationZ(const TFloat angle)
{
	TFloat sine = sinf(angle);
	TFloat cosine = cosf(angle);
	
    AMatrix m;
	m.m[0][0] = (cosine);
	m.m[1][0] = (sine);
	m.m[2][0] = 0.0;
	m.m[3][0] = 0.0;
	
	m.m[0][1] = -(sine);
	m.m[1][1] = (cosine);
	m.m[2][1] = 0.0;
	m.m[3][1] = 0.0;
	
	m.m[0][2] = 0.0;
	m.m[1][2] = 0.0;
	m.m[2][2] = 1.0;
	m.m[3][2] = 0.0;
	
	m.m[0][3] = 0.0;
	m.m[1][3] = 0.0;
	m.m[2][3] = 0.0;
	m.m[3][3] = 1.0;
	
	return m;
}

//==============================================================================

}   //  namespace spcTGame
