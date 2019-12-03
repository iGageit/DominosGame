/**\file Player.cpp
 * \brief Ficheiro com a implementa�o da classe Player
 *
 * @version Projecto 2 - Programa�o - Domino - 10-11 - MIEIC
 * @author Carlos Miguel Correia da Costa - ei09097
 */


#include "Player.h"


//#ifdef USE_BOOST
//	BOOST_CLASS_EXPORT_GUID(Player, "Player")
//#endif


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Default contructor de player
 */
Player::Player() : name("unknown"), AIPlayer(false), score(0), playerBones(vector<Bone*>()) {}


/**
 * Contructor de um player
 * @param _name Nome a dar ao player
 * @param _AIPlayer flag que indica se o player deve ser controlado pela AI (se for true) ou por um utilizador (se for false)
 */
Player::Player(string _name, bool _AIPlayer) : name(_name), AIPlayer(_AIPlayer), score(0) {}


/**
 * Destructor de player
 */
Player::~Player() {}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors-destructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <Player management>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que adiciona um Bone* aos Bones do player
 * @param boneToAdd Bone* a adicionar
 */
void Player::addBone(Bone* boneToAdd) {
	playerBones.push_back(boneToAdd);
}


/**
 * M�todo que retorna o Bone* que est� na posi�o index do vector <Bone*> do player
 * @param index Posi�o do Bone* que se quer
 * @return Bone* que est� na posi�o indicada
 */
Bone* Player::getBone(size_t index) {
	if (index < 0 || index >= playerBones.size())
		return NULL;

	return playerBones[index];
}


/**
 * M�todo que retira todos os bones que estavam associados ao player
 */
void Player::resetPlayerBones() {
	playerBones.clear();
}


/**
 * M�todo que adiciona o numero de pontos dado � pontua�o do player
 * @param points N�mero de pontos a adicionar
 */
void Player::addPoints(unsigned points) {
	score += points;
}


/**
 * M�todo que remove um dado Bone* que esteja associado ao player
 * @param boneToRemove Bone* a remover do player
 */
void Player::removeBone(Bone* boneToRemove) {
	for (vector <Bone*>::iterator itBones = playerBones.begin(); itBones != playerBones.end(); ++itBones) {
		if ((*itBones) == boneToRemove) {
			playerBones.erase(itBones);
			return;
		}
	}
}


/**
 * M�todo que verifica se o player tem um Bone que seja DoubleBone
 * @return True caso o player tenha pelo menos um DoubleBone*
 */
bool Player::playerHasDoubleBones() {
	for (size_t i = 0; i < playerBones.size(); ++i) {
		if (playerBones[i]->isDoubleBone())
			return true;
	}

	return false;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <Player management>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <Player CLI interface>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que mostra os Bones do player na consola
 */
void Player::showPlayerBonesCLI() {
	//tamanho das pe�as + intervalos de 2 espa�os entre elas
	size_t matrixWidth = (size_t)((BONE_HORIZONTAL_WIDTH + 2) * this->playerBones.size() + 0.99);
	if (matrixWidth > BOARD_WIDTH)
		matrixWidth = BOARD_WIDTH;

	size_t numBonesPerRow = (size_t)((double)matrixWidth / (double)(BONE_HORIZONTAL_WIDTH + 2));
	size_t numRows = (size_t)((double)(playerBones.size() / (double)numBonesPerRow) + 0.99); //para arredondar para cima quando o resultado n�o for inteiro

	if (this->playerBones.empty()) {
		cout << "The player " << this->name << " There are no Bones!" << endl;
		return;
	}

	cout << "  >>> Player Bones " << this->name << " <<<" << "\n";



	size_t currentBoneIndex = 0;
	for (size_t rowNum = 0; rowNum < numRows; ++rowNum) {
		if (currentBoneIndex >= playerBones.size())
			break;

		vector <vector <char> > charMatrix(BONE_HORIZONTAL_HEIGHT, vector <char>(matrixWidth, BOARD_BACKGROUND_CHAR));
		size_t currentBoneXCenter = (size_t)((BONE_HORIZONTAL_WIDTH + 2) / 2 + 0.99);
		size_t currentBoneYCenter = BONE_HORIZONTAL_HEIGHT / 2;

		for (size_t numBoneRow = 0; numBoneRow < numBonesPerRow; ++numBoneRow) {
			if (currentBoneIndex >= playerBones.size())
				break;

			cout << " #  <" << currentBoneIndex << (currentBoneIndex < 10 ? ">  # " : "> # ");
			Board::drawBoneOnMatrix(playerBones[currentBoneIndex], charMatrix, currentBoneXCenter, currentBoneYCenter, false);
			currentBoneXCenter += (BONE_HORIZONTAL_WIDTH + 2);

			++currentBoneIndex;
		}

		cout << "\n";

		for (size_t y = 0; y < charMatrix.size(); ++y) {
			for (size_t x = 0; x < charMatrix[0].size(); ++x) {
				cout << charMatrix[y][x];
			}
			cout << "\n";
		}

		cout << endl;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </Player CLI interface>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string Player::getName() const {
	return name;
}

bool Player::getAIPlayer() const {
	return AIPlayer;
}

unsigned Player::getScore() const {
	return score;
}

vector<Bone*>& Player::getPlayerBones() {
	return playerBones;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <Sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Player::setName(string name) {
	this->name = name;
}

void Player::setAIPlayer(bool AIPlayer) {
	this->AIPlayer = AIPlayer;
}

void Player::setScore(unsigned newScore) {
	this->score = newScore;
}

void Player::setPlayerBones(const vector<Bone*>& playerBones) {
	this->playerBones = playerBones;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </Sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
