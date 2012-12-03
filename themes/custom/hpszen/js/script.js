/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.hpszen = {
    attach: function (context, settings) {

      // Primary navigation menu
      $('#navigation', context).once('hpszen', function () {

        Drupal.theme.hpszenSubmenuToggle = function () {
          return '<a href="#" class="submenu-toggle" title="' +
                 Drupal.t("Javascript trigger to add or remove this item's " +
                          "submenu from the visual display.") +
                 '">&or;</a>';
        };

        Drupal.theme.hpszenToggleMenuTrigger = function () {
          return '<a class="menu-toggle" href="#">' + Drupal.t('Menu') + '</a>';
        };

        function toggleMenu(event) {
          event.preventDefault();
          event.stopPropagation();
          $(event.data.menu).toggleClass('element-invisible');
          if (event.data.title) {
            $(event.data.title).toggleClass('expanded');
          };
        }

        $(this).find('ul').addClass('element-invisible');
        $(this).find('li.expanded').each(function () {
          var li = $(this);
          li.prepend(Drupal.theme('hpszenSubmenuToggle'));
          li.find('a.submenu-toggle').bind('click', { menu: $(this).find('> ul') }, toggleMenu);
        });

        $(this).once('adjustnavigation', function () {
          var nav = $(this);
          // Conditional must match the media query threshold for horizontal menu in CSS
          // @see sass/layouts/responsive.scss
          if ($(document).width() < 699) {
            // Convert navigation to vertical toggle menu
            nav.addClass('toggle-menu');
            nav.find('.block-menu').each(function () {

              var menuBlock           = $(this),
                  title               = menuBlock.find('> h2')[0],
                  rootMenu            = menuBlock.find('> ul')[0],
                  itemsWithSubmenus   = menuBlock.find('li.expanded');

              // Add link to title and bind click event to it for main menu toggle
              $(title).wrapInner('<a href="#" />')
              .find('a').bind('click', {menu: rootMenu, title: title}, toggleMenu);

              $(rootMenu).addClass('element-invisible');

            });
          }
          else {
            // Show root menu
            nav.find('.block-menu > ul').removeClass('element-invisible');
          }
        })

        $(window).bind('load resize orientationchange', function () {
          $('#navigation').trigger('adjustnavigation');
        });

      });

      // Slideshow
      $('.slides', context).once('hpszen', function () {

        if ("cycle" in $.fn) {

          Drupal.theme.hpszenCyclingPager = function () {
            return '<div class="pager"></div>';
          };
          Drupal.theme.hpszenCyclingNav = function () {
            // @todo Drupal.t
            return '<div class="nav">' +
                   '  <a href="#" title="Javascript trigger to display previous slide." id="hpszen-slide-previous">Previous</a>' +
                   '  <a href="#" title="Javascript trigger to pause slideshow." id="hpszen-slides-pause">Pause</a>' +
                   '  <a href="#" title="Javascript trigger to resume slideshow." id="hpszen-slides-resume">Resume</a>' +
                   '  <a href="#" title="Javascript trigger to display next slide." id="hpszen-slide-next">Next</a>' +
                   '</div>';
          };

          Drupal.theme.hpszenCyclingPagerItem = function (index, slide) {
            var slide = $(slide),
                alt = slide.find('> p').text() || '',
                image = slide.find('> span img');
            return '<a title="' + Drupal.t('Slide number @index.', { '@index': index + 1 }) + '" href="#"><img src="' + image.attr('src') + '" alt="' + alt + '"/></a>';
          };

          function pagerItem(index, slide) {
            return Drupal.theme('hpszenCyclingPagerItem', index, slide);
          }

          // Called on image load, window resize and after slide transition.
          function positionImage(image) {
            var container = $(image).closest('span'),
                showing = (container.height() / image.height),
                margin  = 0;
            if (!container.width() > 0 || !image.width > 0) return; // Stop if slide hidden
            switch (true) {
              case showing < 0.3:
                margin = (image.height * -0.3);
                break;
              case showing < 0.4:
                margin = (image.height * -0.2);
                break;
              case showing < 0.5:
                margin = (image.height * -0.14);
                break;
              case showing < 0.6:
                margin = (image.height * -0.09);
                break;
              default:
                // Most of the image is showing, do nothing
            }
            $(image).css('margin-top', Math.floor(margin) + 'px');
          }

          // Assumes slides are in .view-content:
          var slides = $(this),
              images = $(this).find('> span img');
          slides.closest('.view-content').addClass('cycling');

          images.one('load', function () {
            positionImage(this);
          }).each(function () {
            if (this.complete) $(this).load();
          });

          //slides.parent().append(Drupal.theme('hpszenCyclingPager'));
          slides.parent().append(Drupal.theme('hpszenCyclingNav'));

          slides.cycle({
            //pager:  '.pager',
            //pagerAnchorBuilder: pagerItem,
            prev: '#hpszen-slide-previous',
            next: '#hpszen-slide-next',
            pause: 1,
            speed: 1000,
            fastOnEvent: 200,
            delay: -2000,
            timeout: 15000,
            after: function () {
              positionImage($(this).find('> span img')[0]);
            }
          });

          $('#hpszen-slides-pause').click(function() {
            console.log(slides);
            slides.cycle('pause');
            slides.addClass('paused');
            $(this).parent().addClass('paused');
            event.preventDefault();
            event.stopPropagation();
          });
          $('#hpszen-slides-resume').click(function() {
            slides.removeClass('paused');
            $(this).parent().removeClass('paused');
            slides.cycle('resume');
            event.preventDefault();
            event.stopPropagation();
          });

          $(window).bind('resize', function () {
            slides.each(function () {
              $(this).width($(this).closest('.view-content').width());
              positionImage($(this).find('> span img')[0]);
            });
          });
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
