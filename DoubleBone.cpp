/**\file DoubleBone.cpp
 * \brief Ficheiro com a implementa�o da classe DoubleBone.
 *
 * @version Projecto 2 - Programa�o - Domino - 10-11 - MIEIC
 * @author Carlos Miguel Correia da Costa - ei09097
 */


#include "DoubleBone.h"


//#ifdef USE_BOOST
//	BOOST_CLASS_EXPORT_GUID(DoubleBone, "DoubleBone")
//#endif


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Default contructor de DoubleBone
 */
DoubleBone::DoubleBone() : Bone(), boneConnectedOnMiddleDownOrLeft(NULL), boneConnectedOnMiddleUpOrRight(NULL) {}


/**
 * Contructor de DoubleBone - subclasse de Bone
 * @param _firstNumber Primeiro n�mero do Bone
 * @param _secondNumber Segundo n�mero do Bone
 * @param _positionOnBonesInUse Posi�o que o DoubleBone ocupa no vector <Bone*> no Boneyard
 * @param _xCenterPosOnBoardMatrix Posi�o no eixo dos x que ocupa na chatMatrix do Board
 * @param _yCenterPosOnBoardMatrix Posi�o no eixo dos y que ocupa na chatMatrix do Board
 * @param _leftSideBone Bone* para o bone que est� conectado do lado esquerdo do Bone a ser criado
 * @param _rigthSideBone Bone* para o bone que est� conectado do lado direito do Bone a ser criado
 * @param _upSideBone Bone* para o bone que est� conectado n parte lateral de cima do Bone a ser criado
 * @param _downSideBone Bone* para o bone que est� connectado n parte lateral de baixo do Bone a ser criado
 * @param _verticalDirection flag que indica se o Bone ficar� na vertical (true) ou horizontal (false)
 */
DoubleBone::DoubleBone(char _firstNumber, char _secondNumber, size_t _positionOnBonesInUse,
		size_t _xCenterPosOnBoardMatrix, size_t _yCenterPosOnBoardMatrix,
		Bone* _leftSideBone, Bone* _rigthSideBone, Bone* _upSideBone, Bone* _downSideBone,
		bool _verticalDirection) :

		Bone(_firstNumber, _secondNumber, _positionOnBonesInUse,
				_xCenterPosOnBoardMatrix, _yCenterPosOnBoardMatrix, _leftSideBone, _rigthSideBone, _verticalDirection),
		boneConnectedOnMiddleDownOrLeft(_upSideBone), boneConnectedOnMiddleUpOrRight(_downSideBone) {}

/**
 * Destructor de DoubleBone
 */
DoubleBone::~DoubleBone() {}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Bone *DoubleBone::getBoneConectedOnMiddleDownOrLeft() const {
	return boneConnectedOnMiddleDownOrLeft;
}

Bone *DoubleBone::getBoneConectedOnMiddleUpOrRight() const {
	return boneConnectedOnMiddleUpOrRight;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void DoubleBone::setBoneConectedOnMiddleDownOrLeft(Bone *boneConnectedOnMiddleDownOrLeft) {
	this->boneConnectedOnMiddleDownOrLeft = boneConnectedOnMiddleDownOrLeft;
}

void DoubleBone::setBoneConectedOnMiddleUpOrRight(Bone *boneConnectedOnMiddleUpOrRight) {
	this->boneConnectedOnMiddleUpOrRight = boneConnectedOnMiddleUpOrRight;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

