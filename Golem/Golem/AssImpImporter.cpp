#include "AssImpImporter.h"
#include "Mesh.h"
#include "Vector3f.h"
#include "Color.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include <assimp/cimport.h>

using namespace Golem::Graphics;
using namespace Golem::Math;
using namespace Golem::Graphics::Importers;

Mesh* AssImpImporter::LoadMesh(const char* meshPath)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(meshPath,
		aiProcess_MakeLeftHanded | 
		aiProcess_FlipWindingOrder | 
		aiProcess_FlipUVs | 
		aiProcess_PreTransformVertices |
		aiProcess_CalcTangentSpace |
		aiProcess_GenSmoothNormals |
		aiProcess_Triangulate |
		aiProcess_FixInfacingNormals |
		aiProcess_FindInvalidData |
		aiProcess_ValidateDataStructure | 0
	);

	if (scene == nullptr) // Something went wrong
	{
		printf("Error Importing Mesh %s Error Message: %s \n", meshPath, importer.GetErrorString());
	}
	else
		return ProcessData(scene);
	return nullptr;
}

Mesh* AssImpImporter::ProcessData(const aiScene* scene)
{
	Mesh* outputMesh = new Mesh();
	for (size_t i = 0; i < scene->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[i];
		if (mesh == nullptr)
		{
			printf("Mesh is null!");
			continue;
		}
		printf("Vertex Count: %i \n", mesh->mNumVertices);
		printf("Face Count: %i \n", mesh->mNumFaces);
		printf("Color Channel Count: %i \n", mesh->GetNumColorChannels());
		printf("UV Channel Count: %i \n", mesh->GetNumUVChannels());

		for (size_t vertexIndex = 0; vertexIndex < mesh->mNumVertices; vertexIndex++)
		{
			auto vertex = mesh->mVertices[vertexIndex];
			outputMesh->AddVertex(Vector3f(vertex.x, vertex.y, vertex.z));

			outputMesh->AddColor(Color(0.0f, 1.0f, 0.0f, 1.0f));

			//auto color = mesh->mColors[0][vertexIndex];
			//outputMesh->AddColor(Color(color.r, color.g, color.b, color.a));
		}

		for (size_t faceIndex = 0; faceIndex < mesh->mNumFaces; faceIndex++)
		{
			auto face = mesh->mFaces[faceIndex];
			for (size_t index = 0; index < face.mNumIndices; index++)
			{
				outputMesh->AddIndex(face.mIndices[index]);
			}
		}

		/*for (size_t colorChannel = 0; colorChannel < mesh->GetNumColorChannels(); colorChannel++)
		{
			if (colorChannel == 0)	// Only supports a channel 0 currently.
			{
				auto colors = mesh->mColors[colorChannel];
				
				for (size_t colorIndex = 0; colorIndex < mesh->mNumVertices; colorIndex++)
				{
					auto color = colors[colorIndex];
					outputMesh->AddColor(Color(color.r, color.g, color.b, color.a));
				}
			}
		}*/
	}
	return outputMesh;
}
