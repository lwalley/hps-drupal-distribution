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

        Drupal.theme.prototype.hpszenSubmenuToggle = function () {
          return '<a href="#" class="submenu-toggle" title="' +
                 Drupal.t("Javascript trigger to add or remove this item's " +
                          "submenu from the visual display.") +
                 '">&or;</a>';
        };

        Drupal.theme.prototype.hpszenSubmenuToggleClosed = function () {
          return '&or;'
        }

        Drupal.theme.prototype.hpszenSubmenuToggleOpen = function () {
          return '&and;'
        }

        Drupal.theme.prototype.hpszenToggleMenuTrigger = function () {
          return '<a class="menu-toggle" href="#">' + Drupal.t('Menu') + '</a>';
        };

        function toggleMenu(event) {
          event.preventDefault();
          event.stopPropagation();
          var toggle = this,
              menu   = (event.data.menu instanceof Array) ? event.data.menu[0] : event.data.menu;

          $(menu).toggleClass('element-invisible');
          // @todo: it seems like there should be a better way to architect this
          //        'now more complex than just a toggle' toggle...

          // If toggling a list item (instead of h2) then alter toggle icon
          if ($(this).parent().get(0).tagName == 'LI') {
            var ul     = $(toggle).closest('ul');

            if ($(menu).hasClass('element-invisible')) {
              $(toggle).html(Drupal.theme('hpszenSubmenuToggleClosed'));
            } else {
              $(toggle).html(Drupal.theme('hpszenSubmenuToggleOpen'));
              // If we just opened the submenu of a root item then close any of its siblings' open menus
              if ($(ul).parent().get(0).tagName != 'LI') {
                $(menu).closest('li').siblings().find('> ul:not(.element-invisible)').siblings('a.submenu-toggle').trigger('click');
              }
            }
          }
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
      // @note To trigger slideshow behaviour add class 'slides' to Views HTML
      //       list, with optional class 'with-pager' to trigger pager
      $('.slides', context).once('hpszen', function () {

        if ("cycle" in $.fn) {

          Drupal.theme.prototype.hpszenCyclingPagerMarkers = function () {
            return '<div class="pager-markers"></div>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerThumbnails = function () {
            return '<div class="pager-thumbnails"></div>';
          };
          Drupal.theme.prototype.hpszenCyclingNav = function () {
            return '<div class="nav">' +
                   '  <a href="#" title="' +
                   Drupal.t("Javascript trigger to display previous slide.") +
                   '" id="hpszen-slide-previous">' + Drupal.t('Previous slide') + '</a>' +
                   '  <a href="#" title="' +
                   Drupal.t("Javascript trigger to pause slideshow.") +
                   '" id="hpszen-slides-pause">' + Drupal.t('Pause slideshow') + '</a>' +
                   '  <a href="#" title="' +
                   Drupal.t("Javascript trigger to resume slideshow.") +
                   '" id="hpszen-slides-resume">' + Drupal.t('Resume slideshow') + '</a>' +
                   '  <a href="#" title="' +
                   Drupal.t("Javascript trigger to display next slide.") +
                   '" id="hpszen-slide-next">' + Drupal.t('Next slide') + '</a>' +
                   '</div>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerMarker = function (index, slide) {
            var slide = $(slide),
                slide_number = index + 1,
                slide_title = slide.find('> h2').text();
            return '<a title="'
              + Drupal.t('Javascript trigger to visually display slide @slide_number.', {'@slide_number': slide_number})
              + '" href="#">'
              + Drupal.t('Slide: @slide_title_or_number', { '@slide_title_or_number': slide_title || slide_number })
              + '</a>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerThumbnail = function (index, slide) {
            var slide = $(slide),
                alt = slide.find('> p').text() || '',
                image = slide.find('> span img');
            return '<a title="' + Drupal.t('Slide number @index.', { '@index': index + 1 }) + '" href="#"><img src="' + image.attr('src') + '" alt="' + alt + '"/></a>';
          };

          function pagerMarker(index, slide) {
            return Drupal.theme('hpszenCyclingPagerMarker', index, slide);
          }
          function pagerThumbnail(index, slide) {
            return Drupal.theme('hpszenCyclingPagerThumbnail', index, slide);
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

          cycle_options = {
            prev: '#hpszen-slide-previous',
            next: '#hpszen-slide-next',
            pause: 1,
            speed: 1000,
            fastOnEvent: 200,
            delay: -3000,
            timeout: 15000,
            after: function () {
              positionImage($(this).find('> span img')[0]);
            }
          }

          slides.parent().append(Drupal.theme('hpszenCyclingNav'));

          if (slides.hasClass('with-pager-markers')) {
            slides.parent().append(Drupal.theme('hpszenCyclingPagerMarkers'));
            cycle_options.pager = '.pager-markers';
            cycle_options.pagerAnchorBuilder = pagerMarker;
          }
          if (slides.hasClass('with-pager-thumbnails')) {
            slides.parent().append(Drupal.theme('hpszenCyclingPagerThumbnails'));
            cycle_options.pager = '.pager-thumbnails';
            cycle_options.pagerAnchorBuilder = pagerThumbnail;
          }

          slides.cycle(cycle_options);

          $('#hpszen-slides-pause').click(function() {
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
