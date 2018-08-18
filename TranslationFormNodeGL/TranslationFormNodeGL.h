//TranslationFormNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the TranslationFormNodeGL class declaration.

#include <Point3Df.h>
#include <Transform4Dd.h>
#include <NodeGL/NodeGL.h>

class TranslationFormNodeGL : public NodeGL
{
 public:
  TranslationFormNodeGL();
  TranslationFormNodeGL(double x,
			double y,
			double z
			);
  TranslationFormNodeGL(TranslationFormNodeGL&);

  ~TranslationFormNodeGL();

  void ActionGL();
 protected:
  Transform4Dd translation;
};
