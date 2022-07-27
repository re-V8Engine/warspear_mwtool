

class EntityCollector
{
private:
	EntityContainer tLocalContainer;
	vector<Entity*> pEntityList;
	CMemory* mem;

public:
	EntityCollector(CMemory* _mem);

	vector<Entity*>* getEntityList() { return &pEntityList; }
	void CollectFromContainer(void* containerAddress);

	void CollectEntities(void* headContainer);
};