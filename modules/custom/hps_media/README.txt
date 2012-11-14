About
-----

Contains miscellaneous functions for dealing with images, audio and videos including:

  * HPS Scale and Crop and HPS Crop functions for the GD image toolkit to generate
    thumbnails that favour the top center area of the image.
  * Media player render element for themeing. Field preprocessor function takes link_field
    URLs and generates player render elements for supported mimetypes, that can then
    be rendered in a theme.

@todo this is a multi-purpose helper module but we may want to seperate out the functions
      into their own modules to avoid module dependency issues e.g. image styles require
      image module but media player render element does not.
