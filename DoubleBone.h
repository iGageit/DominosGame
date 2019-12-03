#ifndef DOUBLEBONE_H_
#define DOUBLEBONE_H_

/**\file DoubleBone.h
 * \brief Classe que representa uma pe�a de um Domino com n�meros iguais.
 *
 * @version Projecto 2 - Programa�o - Domino - 10-11 - MIEIC
 * @author Carlos Miguel Correia da Costa - ei09097
 */


#include "defs.h"
#include "Bone.h"


#ifdef USE_BOOST
	#include <boost/serialization/access.hpp>
	#include <boost/serialization/base_object.hpp>
//	#include <boost/serialization/export.hpp>
#endif


//############################################################   DoubleBone   ###################################################################
/**
 * \brief Classe que representa uma pe�a de um Domino com n�meros iguais.
 */
class DoubleBone : public Bone {
//=============================================================   <private>   ===================================================================
private:
	Bone* boneConnectedOnMiddleDownOrLeft;
	Bone* boneConnectedOnMiddleUpOrRight;


#ifdef USE_BOOST
	friend class boost::serialization::access;

	template<class Archive> void serialize(Archive & archive, const unsigned int version) {
		archive & boost::serialization::base_object<Bone>(*this);
		archive & boneConnectedOnMiddleDownOrLeft;
		archive & boneConnectedOnMiddleUpOrRight;
	}
#endif
//=============================================================   </private>   ==================================================================


//==============================================================   <public>   ===================================================================
public:
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/**
	 * Default contructor de DoubleBone
	 */
	DoubleBone();

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
	 * @param _downSideBone Bone* para o bone que est� conectado n parte lateral de baixo do Bone a ser criado
	 * @param _verticalDirection flag que indica se o Bone ficar� na vertical (true) ou horizontal (false)
	 */
	DoubleBone(char _firstNumber, char _secondNumber, size_t positionOnBonesInUse = -1,
			size_t _xCenterPosOnBoardMatrix = 0, size_t _yCenterPosOnBoardMatrix = 0,
			Bone* _leftSideBone = NULL, Bone* _rigthSideBone = NULL, Bone* _upSideBone = NULL, Bone* _downSideBone = NULL,
			bool _verticalDirection = true);

	/**
	 * Destructor de DoubleBone
	 */
	virtual ~DoubleBone();
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    Bone *getBoneConectedOnMiddleDownOrLeft() const;
    Bone *getBoneConectedOnMiddleUpOrRight() const;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    void setBoneConectedOnMiddleDownOrLeft(Bone *boneConectedOnMiddleDownOrLeft);
    void setBoneConectedOnMiddleUpOrRight(Bone *boneConectedOnMiddleUpOrRight);
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//==============================================================   </public>   ==================================================================
};


#endif /* DOUBLEBONE_H_ */
