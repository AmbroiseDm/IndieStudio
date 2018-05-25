//
// Created by lerest_m on 14/06/17.
//

#ifndef INDIE_STUDIO_DEBUG_HPP
#define INDIE_STUDIO_DEBUG_HPP

class Debug
{
    private:
        static bool debug;

    public:
        /**
         * Set the debug to the given value
         *
         * @param debugValue Value to set
         */
        static void setDebug(bool);

        /**
         * Specify if the debug is actif or not
         *
         * @return true if the debug is actif
         */
        static bool &isDebug();
};

#endif //INDIE_STUDIO_DEBUG_HPP
