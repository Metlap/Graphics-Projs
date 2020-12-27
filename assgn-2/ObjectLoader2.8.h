
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
/**
 *  Loads model from Wavefront Obj file (*.obj). Using triangles and normals
 *  as static object. No texture mapping.
 *
 *  Warning: OBJ files must be triangulated. Non triangulated objects wont
 *           work! You can use Blender to triangulate.
 *
 *  Exporting as Obj File on Blender:
 *           (a) Open Blender program. Create your model.
 *           (b) File -> Export -> Wavefront (.obj)
 *           (c) Now at the left side panel on "Export Obj" section check on
 *               "Triangulate Faces".
 *           (d) Click on "Export OBJ" button. It produce two files. For
 *               example: cube.obj and cube.mtl. We will only need the *.obj
 *               file only.
 *
 *  Sample Usage:
 *          ObjModelLoader *mesh = NULL;
 *          mesh = new ObjModelLoader("C:\\data\\filename.obj");
 *
 *          mesh->Draw();
 *
 */
class ObjModelLoader
{
    public:
        /**
         *  Constructor
         *  @param string filename
         *         File name of the *.obj file with path.
         *         Example: "C:\\data\\cube.obj"
         */
        ObjModelLoader(string filename);

        /**
         *  Destructor
         */
        ~ObjModelLoader();

        /**
         *  Draws model from *.obj file.
         */
        void Draw(float zoomf);

    private:
        string filename = "";

        vector<vector<float>*> *normals = new vector<vector<float>*>;
        vector<vector<float>*> *vertices = new vector<vector<float>*>;
        vector<vector<int>*>   *faces    = new vector<vector<int>*>;
        vector<vector<int>*> *faceNorms  = new vector<vector<int>*>;
        /**
         *  Split string to individual strings according to given option
         *
         *  @param  string text
         *          Text to be splitted
         *
         *          char delimeter
         *          Separator for the string
         *
         *  @return vector<string>*
         *          vector of strings
         *
         *  @example
         *          If text = "Hello World", delimeter = ' '
         *          Then { "Hello", "World" }
         */
        vector<string>* GetSplittedStrings(string text, char delimeter);

        /**
         *  Converts string to float value
         *
         *  @param  string text
         *          Text to be converted
         *
         *  @return float
         *          Converter value
         *
         *  @example
         *          If text = "1.5"
         *          Then 1.5f
         */
        float GetFloatFromString(string text);

        /**
         *  Calculates normal from given points
         *
         *  @param  float *coord1, float *coord2, float *coord3
         *          3 points of the triangle plane to be calculated
         *          for normal
         *
         *  @return float*
         *          Array of float where normal points are located
         *          x, y, z coordinate.
         */
        float* GetNormal(float *coord1, float *coord2, float *coord3);
};


ObjModelLoader::ObjModelLoader(string filename)
{
    this->filename = filename;

    // Open the *.obj file
    fstream *objFile = new fstream;
    objFile->open(filename, ios_base::in);

    // If can't open the file
    if (!objFile->is_open())
    {
        cout << "[!] ERROR: Unable to open the file" << endl;

        // Terminate the program
        exit(EXIT_FAILURE);
    }

    /*
        Sample *.obj file example
		
        # Blender v2.73 (sub 0) OBJ File: ''
        # www.blender.org
        mtllib cube.mtl
        o Cube
        v 1.000000 -1.000000 -1.000000
        v 1.000000 -1.000000 1.000000
        v -1.000000 -1.000000 1.000000
        v -1.000000 -1.000000 -1.000000
        v 1.000000 1.000000 -0.999999
        v 0.999999 1.000000 1.000001
        v -1.000000 1.000000 1.000000
        v -1.000000 1.000000 -1.000000
        usemtl Material
        s off
        f 2 3 4
        f 8 7 6
        f 5 6 2
        f 6 7 3
        f 3 7 8
        f 1 4 8
        f 1 2 4
        f 5 8 6
        f 1 5 2
        f 2 6 3
        f 4 3 8
        f 5 1 8
     */

    string currentLine;

    // Read every line
    while (!objFile->eof())
    {
        getline(*objFile, currentLine);

        // Split every line according to space
        vector<string> *parameters = this->GetSplittedStrings(currentLine, ' ');

        // If current line has information about vertices
        if (parameters->at(0) == "v")
        {

            // Remove 'v' and keep the rest of the numbers
            parameters->erase(parameters->begin());

            vector<float> *currentPoint = new vector<float>;

            for (int index = 0; index < parameters->size(); index++)
            {
                // Convert each x, y, z coordinate (as string) to float value
                currentPoint->push_back(this->GetFloatFromString(parameters->at(index)));
            }
            // cout<<"HI"<<endl;
            // Save that point on "vertices"
            vertices->push_back(currentPoint);
        }
        if (parameters->at(0) == "vn")
        {

            // Remove 'v' and keep the rest of the numbers
            parameters->erase(parameters->begin());

            vector<float> *currentNorm = new vector<float>;

            for (int index = 0; index < parameters->size(); index++)
            {
                // Convert each x, y, z coordinate (as string) to float value
                currentNorm->push_back(this->GetFloatFromString(parameters->at(index)));
                // cout<<this->GetFloatFromString(parameters->at(index))<<" ";
            }
            // cout<<endl;
            // Save that point on "vertices"
            normals->push_back(currentNorm);
        }
        // If current line has information about faces
        else if (parameters->at(0) == "f")
        {
            // Remove 'f' and keep the rest of the numbers
            parameters->erase(parameters->begin());

            vector<int> *vertexIndexes = new vector<int>;
            vector<int> *normIndexes = new vector<int>;

            for (int index = 0; index < parameters->size(); index++)
            {
                vector<string> *token = this->GetSplittedStrings(parameters->at(index), '/');
                // Convert each face index (as string) to integer
                int faceIndex = this->GetFloatFromString(token->at(0));
                // token = strtok(NULL, "/");
                // token = strtok(NULL, "/");
                int facen = this->GetFloatFromString(token->at(2));
                // Our obj file uses indexing from 1. So, we are decrementing 1 to make it start from 0
                vertexIndexes->push_back(--faceIndex);
                normIndexes->push_back(--facen);
                // cout<<"HI"<<vertexIndexes->at(vertexIndexes->size()-1)<<endl;
                // cout<<facen<<" ";
                delete token;
            }

            // cout<<endl;

            // And finally saving faces information
            faces->push_back(vertexIndexes);
            faceNorms->push_back(normIndexes);
        }

        // Freeing unnecessary memory
        delete parameters;
    }

    // Closing the *.obj file
    objFile->close();
}

ObjModelLoader::~ObjModelLoader()
{
    // Freeing unnecessary memory
    delete this->faces;
    delete this->vertices;
}

void ObjModelLoader::Draw(float zoomf)
{
    // We will draw faces as triangles
    glBegin(GL_QUADS);

    // For every faces
    for (int i = 0; i < faces->size(); i++)
    {
        // There will be a normal for lighting
        float *normal = NULL;

        // Since this is triangle, so every face must have 3 vertices
        float coord1[3],
              coord2[3],
              coord3[3],
              coord4[3];

        // For every vertex/point
        for (int j = 0; j < (faces->at(i))->size(); j++)
        {
            int index = (faces->at(i))->at(j);

            switch(j)
            {
                // If 1st vertex, then save it to coord1
                case 0:
                    coord1[0] = (vertices->at(index))->at(0);
                    coord1[1] = (vertices->at(index))->at(1);
                    coord1[2] = (vertices->at(index))->at(2);
                    break;

                // If 2nd vertex, then save it to coord2
                case 1:
                    coord2[0] = (vertices->at(index))->at(0);
                    coord2[1] = (vertices->at(index))->at(1);
                    coord2[2] = (vertices->at(index))->at(2);
                    break;

                // If 3rd vertex, then save it to coord3
                case 2:
                    coord3[0] = (vertices->at(index))->at(0);
                    coord3[1] = (vertices->at(index))->at(1);
                    coord3[2] = (vertices->at(index))->at(2);
                    break;

                // If 3rd vertex, then save it to coord3
                case 3:
                    coord4[0] = (vertices->at(index))->at(0);
                    coord4[1] = (vertices->at(index))->at(1);
                    coord4[2] = (vertices->at(index))->at(2);
                    break;

            }

            // When we got all the 3 point/vertices, then calculate normal and draw the triangle
            if (j == 3)
            {
                // Calculating normal
                    // calculate Vector1 and Vector2
			    float va[3], vb[3], vr[3];

			    va[0] = coord1[0] - coord2[0];
			    va[1] = coord1[1] - coord2[1];
			    va[2] = coord1[2] - coord2[2];

			    vb[0] = coord1[0] - coord3[0];
			    vb[1] = coord1[1] - coord3[1];
			    vb[2] = coord1[2] - coord3[2];

			    // cross product
			    vr[0] = va[1] * vb[2] - vb[1] * va[2];
			    vr[1] = vb[0] * va[2] - va[0] * vb[2];
			    vr[2] = va[0] * vb[1] - vb[0] * va[1];

			    // normalization factor
			    float val = sqrt(pow(vr[0], 2) + pow(vr[1], 2) + pow(vr[2], 2));

			    float norm[3] = {0.0,0.0,0.0};

			    norm[0] = vr[0] / val;
			    norm[1] = vr[1] / val;
			    norm[2] = vr[2] / val;

                // normal = this->GetNormal(coord1, coord2, coord3);
                normal = norm;

                // Setting normal for these vertices
                glNormal3f(normal[0], normal[2], normal[2]);

                // Drawing the triangle as a face
                glVertex3f(coord1[0]*zoomf, coord1[1]*zoomf, coord1[2]*zoomf);
                glVertex3f(coord2[0]*zoomf, coord2[1]*zoomf, coord2[2]*zoomf);
                glVertex3f(coord3[0]*zoomf, coord3[1]*zoomf, coord3[2]*zoomf);
                glVertex3f(coord4[0]*zoomf, coord4[1]*zoomf, coord4[2]*zoomf);

            }
        }
    }

    // // For every faces
    // for (int i =  faces->size()-1; i >=0; i--)
    // {
    //     // There will be a normal for lighting
    //     float *normal = NULL;

    //     // Since this is triangle, so every face must have 3 vertices
    //     float coord1[3],
    //           coord2[3],
    //           coord3[3];

    //     // For every vertex/point
    //     for (int j = (faces->at(i))->size()-1; j >=0; j--)
    //     {
    //         int index = (faces->at(i))->at(j);

    //         switch(j)
    //         {
    //             // If 1st vertex, then save it to coord1
    //             case 0:
    //                 coord1[0] = (vertices->at(index))->at(0);
    //                 coord1[1] = (vertices->at(index))->at(1);
    //                 coord1[2] = (vertices->at(index))->at(2);
    //                 break;

    //             // If 2nd vertex, then save it to coord2
    //             case 1:
    //                 coord2[0] = (vertices->at(index))->at(0);
    //                 coord2[1] = (vertices->at(index))->at(1);
    //                 coord2[2] = (vertices->at(index))->at(2);
    //                 break;

    //             // If 3rd vertex, then save it to coord3
    //             case 2:
    //                 coord3[0] = (vertices->at(index))->at(0);
    //                 coord3[1] = (vertices->at(index))->at(1);
    //                 coord3[2] = (vertices->at(index))->at(2);
    //                 break;
    //         }

    //         // When we got all the 3 point/vertices, then calculate normal and draw the triangle
    //         if (j == 2)
    //         {
    //             // Calculating normal
    //                 // calculate Vector1 and Vector2
			 //    float va[3], vb[3], vr[3];

			 //    va[0] = coord1[0] - coord2[0];
			 //    va[1] = coord1[1] - coord2[1];
			 //    va[2] = coord1[2] - coord2[2];

			 //    vb[0] = coord1[0] - coord3[0];
			 //    vb[1] = coord1[1] - coord3[1];
			 //    vb[2] = coord1[2] - coord3[2];

			 //    // cross product
			 //    vr[0] = va[1] * vb[2] - vb[1] * va[2];
			 //    vr[1] = vb[0] * va[2] - va[0] * vb[2];
			 //    vr[2] = va[0] * vb[1] - vb[0] * va[1];

			 //    // normalization factor
			 //    float val = sqrt(pow(vr[0], 2) + pow(vr[1], 2) + pow(vr[2], 2));

			 //    float norm[3] = {0.0,0.0,0.0};

			 //    norm[0] = vr[0] / val;
			 //    norm[1] = vr[1] / val;
			 //    norm[2] = vr[2] / val;

    //             // normal = this->GetNormal(coord1, coord2, coord3);
    //             normal = norm;

    //             // Setting normal for these vertices
    //             glNormal3f(normal[0], normal[2], normal[2]);

    //             // Drawing the triangle as a face
    //             glVertex3f(coord1[0], coord1[1], coord1[2]);
    //             glVertex3f(coord2[0], coord2[1], coord2[2]);
    //             glVertex3f(coord3[0], coord3[1], coord3[2]);

    //         }
    //     }
    // }

    glEnd();
}

vector<string>* ObjModelLoader::GetSplittedStrings(string text, char delimeter)
{
    text += delimeter;

    string word = "";
    vector<string> *words = new vector<string>;

    for (int character = 0; character < text.length(); character++)
    {
        if (text[character] != delimeter)
        {
            word += text[character];
        }
        else
        {
            words->push_back(word);
            word = "";
        }
    }

    return words;
}

float ObjModelLoader::GetFloatFromString(string text)
{
    float value = 0.0f;

    istringstream buffer(text);
    buffer >> value;

    return value;
}

// float* ObjModelLoader::GetNormal(float *coord1, float *coord2, float *coord3)
// {
//     // calculate Vector1 and Vector2
//     float va[3], vb[3], vr[3];

//     va[0] = coord1[0] - coord2[0];
//     va[1] = coord1[1] - coord2[1];
//     va[2] = coord1[2] - coord2[2];

//     vb[0] = coord1[0] - coord3[0];
//     vb[1] = coord1[1] - coord3[1];
//     vb[2] = coord1[2] - coord3[2];

//     // cross product
//     vr[0] = va[1] * vb[2] - vb[1] * va[2];
//     vr[1] = vb[0] * va[2] - va[0] * vb[2];
//     vr[2] = va[0] * vb[1] - vb[0] * va[1];

//     // normalization factor
//     float val = sqrt(pow(vr[0], 2) + pow(vr[1], 2) + pow(vr[2], 2));

//     float norm[3] = {0.0,0.0,0.0};

//     norm[0] = vr[0] / val;
//     norm[1] = vr[1] / val;
//     norm[2] = vr[2] / val;

//     return norm;
// }
